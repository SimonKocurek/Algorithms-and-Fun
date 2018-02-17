#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool palindrome_permutation(string str) {
    auto whitespaces = remove(str.begin(), str.end(), ' ');
    str.erase(whitespaces, str.end());

    unordered_map<char, int> letter_count;
    for (auto c : str) {
        letter_count[c]++;
    }

    int allowed_odd_count = str.size() % 2;
    for (auto &char_count : letter_count) {
        allowed_odd_count -= char_count.second % 2;
        if (allowed_odd_count < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << palindrome_permutation("test") << '\n';
    cout << palindrome_permutation("taco cat") << '\n';
    cout << palindrome_permutation("haha haha") << '\n';

    return 0;
}

