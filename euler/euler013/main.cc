#include <algorithm>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>


int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <file>\n", argv[0]);
    exit(1);
  }

  std::ifstream file(argv[1]);
  std::string line;
  std::vector<std::vector<int>> numbers;

  // Read file containing numbers
  while (std::getline(file, line)) {
    std::vector<int> number;
    for (char ch : line) {
      int digit = static_cast<int>(ch) - 48;
      // printf("ch: %c, digit: %d\n", ch, digit);
      number.push_back(digit);
    }
    std::reverse(number.begin(), number.end());
    numbers.push_back(number);
  }

  // Work out the sum
  std::vector<int> sum(100, 0);
  int tmp, carry = 0;

  for (size_t i = 0; i < numbers.size(); ++i) {
    for (size_t j = 0; j < numbers[i].size(); ++j) {
      tmp = sum[j] + numbers[i][j] + carry;
      sum[j] = tmp % 10;
      carry = tmp / 10;
    }
    size_t j = numbers[i].size();
    while (carry) {
      tmp = sum[j] + carry;
      sum[j] = tmp % 10;
      carry = tmp / 10;
      ++j;
    }
  }

  std::reverse(sum.begin(), sum.end());

  printf("Sum: ");
  for (size_t i = 0; i < sum.size(); ++i) {
    printf("%d", sum[i]);
  }
  printf("\n");

  return 0;
}
