#include "bit_counter.h"
#include "types.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <filesystem>
#include <string>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

void run_test_suite(
    u32 bit_count_lhs,
    u32 bit_count_rhs,
    const std::vector<std::filesystem::path> &input_files,
    std::string const &output_dir) {
  fmt::print("--- Running suite with parameters ---\n");
  fmt::print("\tBit count lhs: {}\n", bit_count_lhs);
  fmt::print("\tBit count rhs: {}\n", bit_count_rhs);

  auto out_name = fmt::format("{}/{}-{}", output_dir, bit_count_lhs, bit_count_rhs);
  auto out = std::ofstream(out_name, std::ios_base::trunc);

  auto max_num_lhs = max_num(bit_count_lhs);
  auto max_num_rhs = max_num(bit_count_rhs);

  out << input_files.size() << std::endl;
  
  for(u32 l = 0; l < max_num_lhs; ++l) {
    out << fmt::format(fmt::format("{{:0{}b}} ", bit_count_lhs), l);
  }
  out << std::endl;

  for(u32 r = 0; r < max_num_rhs; ++r) {
    out << fmt::format(fmt::format("{{:0{}b}} ", bit_count_rhs), r);
  }
  out << std::endl;

  auto test_count = input_files.size();
  auto bit_results = std::vector<bit_result>(test_count);
  for(u32 i = 0; i < test_count; ++i) {
    auto res = count_bits(bit_count_lhs, bit_count_rhs, input_files[i], true);

    out << input_files[i].filename().string() << std::endl;
    out << res.total_ops << std::endl;
    for(u32 l = 0; l < max_num_lhs; ++l) {
      u64 stat_sum = 0;
      for(u32 r = 0; r < max_num_rhs; ++r) {
        stat_sum += res.stats[l][r];
        out << res.stats[l][r] << ' ';
      }
      out << stat_sum << std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
  if(argc != 3) {
    std::cerr << "Not enough arguments. Exiting..." << std::endl;
    return -1;
  }

  auto& input_dir = argv[1];
  auto& output_dir = argv[2];
  auto suite_input = std::vector<std::filesystem::path>();

  for(const auto& entry : std::filesystem::directory_iterator(input_dir)) {
    if(!entry.is_regular_file())
      continue;
    suite_input.push_back(entry.path());
  }

  std::filesystem::create_directory(output_dir);
  run_test_suite(2, 1, suite_input, output_dir);
  run_test_suite(2, 2, suite_input, output_dir);
  run_test_suite(4, 2, suite_input, output_dir);
  run_test_suite(4, 4, suite_input, output_dir);

  return 0;
}
