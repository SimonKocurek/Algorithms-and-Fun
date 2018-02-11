#include <vector>
#include <unordered_set>
#include <iostream>

int count_pairs_with_difference(std::vector<int> numbers, int difference) {
    std::unordered_set<int> numbers_set(numbers.begin(), numbers.end());
    int count = 0;
    for (auto &number : numbers) {
        if (numbers_set.find(number + difference) != numbers_set.end()) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> numbers {2, 3, 4, 6, 7, 8, 10};
    std::cout << count_pairs_with_difference(numbers, 2);
    std::vector<int> numbers2 {1, 7, 5, 9, 2, 12, 3};
    std::cout << count_pairs_with_difference(numbers2, 2);
    return 0;
}

