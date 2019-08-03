#include <iostream>
#include <unordered_map>
#include <vector>

typedef std::pair<int, int> pair;
typedef std::vector<pair> nominators;

void print_solutions(int up_to) {
    std::unordered_map<int, nominators> nominators_with_sum;
    
    for (int a = 1; a <= up_to; ++a) {
        for (int b =1; b <= up_to; ++b) {
            nominators_with_sum[a * a * a + b * b * b].push_back(pair(a, b));
        }
    }

    for (auto &possible_nominators : nominators_with_sum) {
        for (auto &left_nominators : possible_nominators.second) {
            for (auto &right_nominators : possible_nominators.second) {
                std::cout << left_nominators.first << " " << left_nominators.second <<
                " = "
                << right_nominators.first << " " << right_nominators.second << '\n';
            }
        }
    }
}

int main() {
    print_solutions(100);
    return 0;
}

