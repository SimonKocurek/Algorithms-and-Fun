#include <iostream>

using namespace std;

string compress(string s) {
    string result;
    int char_count = 1;

    for (int i = 0; i < s.length(); ++i) {
        if (i + 1 == s.length() || s[i] != s[i + 1]) {
            result += s[i];
            result += char_count + '0';

            char_count = 1;
        } else {
            char_count++;
        }
    }

    return s.length() > result.length() ? result : s;
}

int main() {
    cout << compress("abcd") << '\n';
    cout << compress("aabccccaaa") << '\n';
    cout << compress("AAaaBBB") << '\n';

    return 0;
}

