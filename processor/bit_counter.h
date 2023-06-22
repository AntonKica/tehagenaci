#pragma once
#include "types.h"

#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

#define FMT_HEADER_ONLY
#include <fmt/core.h>

u32 max_num(u32 bit_count) {
  return 1 << bit_count;
}
using stat_matrix = std::vector<std::vector<u64>>;
stat_matrix create_stat_matrix(u32 bit_count_lhs, u32 bit_count_rhs) {
  return stat_matrix(max_num(bit_count_lhs), std::vector<u64>(max_num(bit_count_rhs), 0));
}

struct bit_result {
  u64 total_ops;
  stat_matrix stats;
};
struct cursor {
  u64 pos;
  u32 bit_offset;

  u32 val;
};

b32 next_value(cursor &c, std::vector<u8> const &data, u32 bit_count) {
  if(c.pos >= data.size())
    return false;

  c.val = 0;

  for(u32 i = 0; i < bit_count; ++i) {
    if(c.bit_offset == 8) {
      c.bit_offset = 0;

      if(++c.pos >= data.size())
        return false;
    }
    
    u8 bit = (data[c.pos] >> c.bit_offset++) & 1;
    c.val |= bit << i;
  }

  return true;
}

bit_result count_bits(
    u32 bit_count_lhs,
    u32 bit_count_rhs,
    std::vector<u8> const &data,
    b32 print_progress) {

  auto stats = create_stat_matrix(bit_count_lhs, bit_count_rhs);

  u64 ops_total = data.size() * 8 / bit_count_lhs;
  u64 ops_counter = 0;
  u64 ops_checkpoint = std::max<u64>(1, ops_total / 10);

  if(print_progress)
    fmt::print("\tStarting\n");
  for(auto lhs = cursor{.pos = 0, .bit_offset = 0, .val  = 0 };;){
    if(!next_value(lhs, data, bit_count_lhs))
      break;

    auto rhs = lhs;
    if(!next_value(rhs, data, bit_count_rhs))
      break;

    ++stats[lhs.val][rhs.val];
    ++ops_counter;

    if(print_progress){
      if(ops_counter % ops_checkpoint == 0) {
        fmt::print("\tProgress {:d}%\n", ops_counter * 100 / ops_total);
      }
    }
  }

  if(print_progress)
    fmt::print("\tDONE\n");

  bit_result res;
  res.total_ops = ops_counter;
  res.stats = stats;

  return res;
}

bit_result count_bits(
    u32 bit_count_lhs,
    u32 bit_count_rhs,
    const std::filesystem::path &input_file,
    b32 print_progress) {

  auto max_num_lhs = max_num(bit_count_lhs);
  auto max_num_rhs = max_num(bit_count_rhs);

  // do we need this?
  auto mask_lhs = max_num_lhs - 1;
  auto mask_rhs = max_num_rhs - 1;

  auto in = std::ifstream(input_file, std::ifstream::binary | std::ifstream::ate );
  // res.name = input_file.filename().string();
  auto filesize = in.tellg();
  in.seekg(0);

  auto file_buffer = std::vector<u8>(filesize);
  in.read(reinterpret_cast<char *>(file_buffer.data()), filesize);
  in.close();

  return count_bits(bit_count_lhs, bit_count_rhs, file_buffer, print_progress);
}
