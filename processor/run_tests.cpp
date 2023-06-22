#include "bit_counter.h"

#define FMT_HEADER_ONLY
#include <fmt/core.h>

void test(std::string const &name, u32 bit_count_lhs, u32 bit_count_rhs, std::vector<u8> const &data, stat_matrix const &expected_stats) {
  fmt::print("[START] {} - {}:{} - [", name, bit_count_lhs, bit_count_rhs);
  for(u32 i = 0; i < data.size(); ++i) {
    fmt::print("{:#010b}", data[i]);
    if(i + 1 < data.size())
      fmt::print(",");

  }
  fmt::print("]\n");

  auto actual_bits = count_bits(bit_count_lhs, bit_count_rhs, data, false);
  auto &actual_stats = actual_bits.stats;

  // compare sizes
  if(expected_stats.size() != actual_stats.size()) {
    fmt::print("[ERROR] Wrong row count. Expected: {:d} Actual: {:d}\n",
        expected_stats.size(), actual_stats.size());
    fmt::print("[FAIL ] {}\n", name);
    return;
  }

  if(expected_stats[0].size() != actual_stats[0].size()) {
    fmt::print("[ERROR] Wrong column count. Expected: {:d} Actual: {:d}\n"
        , expected_stats[0].size(), actual_stats[0].size());
    fmt::print("[FAIL ] {}\n", name);
    return;
  }

  b32 ok = true;
  auto errors = std::vector<std::string>();
  for(u32 col = 0; col < expected_stats.size(); ++col) {
    for(u32 row = 0; row < expected_stats[col].size(); ++row) {
      if(expected_stats[col][row] != actual_stats[col][row]) {
        fmt::print("[ERROR] Wrong bit count for {:#010b}->{:#010b}. Expected:{:d} Actual:  {:d}\n",
            col, row, expected_stats[col][row], actual_stats[col][row]);
      }
    }
  }

  if(ok) {
    fmt::print("[ OK  ] {}\n", name);
  } else {
    fmt::print("[FAIL ] {}\n", name);
  }
}

void test_speed() {
    u64 mb = 100;
    u64 one_hundred_mb = (1024 * 1024) * mb;
    auto data = std::vector<u8>(one_hundred_mb);
    std::srand(0);
    for(auto &a : data)
      a = std::rand();

    auto begin = std::chrono::high_resolution_clock::now();
    count_bits(1, 1, data, false);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    auto sgb = (double)duration_ms / 1000 / mb * 1000;

    fmt::print("[{:2d}->{:2d}] {}MB of random data took {}ms, 1GB would take {:.2f}s\n", 1, 1, mb, duration_ms, sgb);
}

int main() {
  fmt::print("--- Running correctness tests ---\n"); 
  {
    auto data = std::vector<u8>{0b00000000};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 7;
    expected_stats[0b0][0b1] = 0;
    expected_stats[0b1][0b0] = 0;
    expected_stats[0b1][0b1] = 0;

    test("Byte of zeroes", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b00000000};
    auto expected_stats = create_stat_matrix(2,1);
    expected_stats[0b00][0b0] = 3;
    expected_stats[0b00][0b1] = 0;
    expected_stats[0b01][0b0] = 0;
    expected_stats[0b01][0b1] = 0;
    expected_stats[0b10][0b0] = 0;
    expected_stats[0b10][0b1] = 0;
    expected_stats[0b11][0b0] = 0;
    expected_stats[0b11][0b1] = 0;

    // why assert error?
    test("Byte of zeroes", 2, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b11111111};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 0;
    expected_stats[0b0][0b1] = 0;
    expected_stats[0b1][0b0] = 0;
    expected_stats[0b1][0b1] = 7;

    test("Byte of ones", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b11111111};
    auto expected_stats = create_stat_matrix(2,1);
    expected_stats[0b00][0b0] = 0;
    expected_stats[0b00][0b1] = 0;
    expected_stats[0b01][0b0] = 0;
    expected_stats[0b01][0b1] = 0;
    expected_stats[0b10][0b0] = 0;
    expected_stats[0b10][0b1] = 0;
    expected_stats[0b11][0b0] = 0;
    expected_stats[0b11][0b1] = 3;

    test("Byte of ones", 2, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b11110000};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 3;
    expected_stats[0b0][0b1] = 1;
    expected_stats[0b1][0b0] = 0;
    expected_stats[0b1][0b1] = 3;

    test("Byte of four ones and four zeroes", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b11110000};
    auto expected_stats = create_stat_matrix(2,1);
    expected_stats[0b00][0b0] = 1;
    expected_stats[0b00][0b1] = 1;
    expected_stats[0b01][0b0] = 0;
    expected_stats[0b01][0b1] = 0;
    expected_stats[0b10][0b0] = 0;
    expected_stats[0b10][0b1] = 0;
    expected_stats[0b11][0b0] = 0;
    expected_stats[0b11][0b1] = 1;

    test("Byte of four ones and four zeroes", 2, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b10101010};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 0;
    expected_stats[0b0][0b1] = 4;
    expected_stats[0b1][0b0] = 3;
    expected_stats[0b1][0b1] = 0;

    test("Byte of alternating ones and zeroes", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b00000000, 0b00000000};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 15;
    expected_stats[0b0][0b1] = 0;
    expected_stats[0b1][0b0] = 0;
    expected_stats[0b1][0b1] = 0;

    test("Two bytes of zeroes", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b00000000, 0b11111111};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 7;
    expected_stats[0b0][0b1] = 1;
    expected_stats[0b1][0b0] = 0;
    expected_stats[0b1][0b1] = 7;

    test("Byte of ones and byte of zeroes", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b10101010, 0b10101010};
    auto expected_stats = create_stat_matrix(1,1);
    expected_stats[0b0][0b0] = 0;
    expected_stats[0b0][0b1] = 8;
    expected_stats[0b1][0b0] = 7;
    expected_stats[0b1][0b1] = 0;

    test("Two bytes of alternating ones and zeroes", 1, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b10101010, 0b10101010};
    auto expected_stats = create_stat_matrix(3,1);
    expected_stats[0b000][0b0] = 0;
    expected_stats[0b000][0b1] = 0;
    expected_stats[0b001][0b0] = 0;
    expected_stats[0b001][0b1] = 0;
    expected_stats[0b010][0b0] = 0;
    expected_stats[0b010][0b1] = 3;
    expected_stats[0b011][0b0] = 0;
    expected_stats[0b011][0b1] = 0;
    expected_stats[0b100][0b0] = 0;
    expected_stats[0b100][0b1] = 0;
    expected_stats[0b101][0b0] = 2;
    expected_stats[0b101][0b1] = 0;
    expected_stats[0b110][0b0] = 0;
    expected_stats[0b110][0b1] = 0;
    expected_stats[0b111][0b0] = 0;
    expected_stats[0b111][0b1] = 0;

    test("Two bytes of alternating ones and zeroes", 3, 1, data, expected_stats);
  }
  {
    auto data = std::vector<u8>{0b10101010, 0b10101010};
    auto expected_stats = create_stat_matrix(1,3);
    expected_stats[0b0][0b000] = 0;
    expected_stats[0b0][0b001] = 0;
    expected_stats[0b0][0b010] = 0;
    expected_stats[0b0][0b011] = 0;
    expected_stats[0b0][0b100] = 0;
    expected_stats[0b0][0b101] = 7;
    expected_stats[0b0][0b110] = 0;
    expected_stats[0b0][0b111] = 0;
    expected_stats[0b1][0b000] = 0;
    expected_stats[0b1][0b001] = 0;
    expected_stats[0b1][0b010] = 6;
    expected_stats[0b1][0b011] = 0;
    expected_stats[0b1][0b100] = 0;
    expected_stats[0b1][0b101] = 0;
    expected_stats[0b1][0b110] = 0;
    expected_stats[0b1][0b111] = 0;

    test("Two bytes of alternating ones and zeroes", 1, 3, data, expected_stats);
  }
  fmt::print("--- Running speed test ---\n"); 
  {

    test_speed();
  }

  fmt::print("--- Finished tests ---\n");

  return 0;
}
