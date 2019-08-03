#include <iostream>
#include <vector>

using namespace std;

struct palindrome {
    bool valid;
    bool calculated;
};

vector<vector<palindrome>> cache;
vector<bool> delimiters;
string input;

void print_palindromic_partitions() {
    for (int i = 0; i < input.length(); ++i) {
        cout << input[i];

        if (delimiters[i]) {
            cout << ' ';
        }
    }

    cout << '\n';
}

bool is_palindrome(int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
        if (input[i] != input[j]) {
            return false;
        }
    }

    return true;
}

void starting(int index) {
    if (index == input.length()) {
        print_palindromic_partitions();
        return;
    }

    for (int i = index; i < input.length(); ++i) {
        if (!cache[index][i].calculated) {
            cache[index][i].calculated = true;
            cache[index][i].valid = is_palindrome(index, i);
        }

        if (cache[index][i].valid) {
            delimiters[i] = true;
            starting(i + 1);
            delimiters[i] = false;
        }
    }
}

int main() {
    cin >> input;

    delimiters.reserve(input.length());
    fill(delimiters.begin(), delimiters.end(), false);

    cache.reserve(input.length());
    for (int i = 0; i < input.length(); ++i) {
        cache[i].reserve(input.length());
    }

    starting(0);

    return 0;
}
