#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint64_t sets;
  cin >> sets;

  for (int j = 0; j < sets; ++j) {
    uint64_t size;
    cin >> size;

    vector<int> numbers(size);
    for (auto &number : numbers) {
      cin >> number;
    }

    if (size <= 0) {
      return -1;
    }

    int max = numbers[0];
    int subarray_max = numbers[0];
    for (int i = 1; i < size; ++i) {
      subarray_max = std::max(subarray_max + numbers[i], numbers[i]);
      max = std::max(max, subarray_max);
    }
    cout << max << '\n';
  }

  return 0;
}
