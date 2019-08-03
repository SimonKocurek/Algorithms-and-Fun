#include <bits/stdc++.h>

using namespace std;

struct result {
    int start;
    int length;
};

bool valid(string& str, int i) {
    return i >= 0 && i < str.length();
}

result check_odd_palindrome(string& str, int i) {
    result res {i, 1};

    for (int j = 1; valid(str, i - j) && valid(str, i +j); ++j) {
        if (str[i - j] != str[i + j]) {
            break;
        }

        res.start--;
        res.length += 2;
    }

    return res;
}

result check_even_palindrome(string& str, int i) {
    if (!valid(str, i + 1) || str[i] != str[i + 1]) {
        return {i, 0};
    }

    result res {i, 2};

    for (int j = 1; valid(str, i - j) && valid(str, i + 1 + j); ++j) {
        if (str[i - j] != str[i + 1 + j]) {
            break;
        }

        res.start--;
        res.length += 2;
    }

    return res;
}

string longest(string str) {
    result res {0, 0};

    for (int i = 0; i < str.size(); ++i) {
        auto odd_palindrome = check_odd_palindrome(str, i);
        auto even_palindrome = check_even_palindrome(str, i);

        if (odd_palindrome.length > res.length) {
            res = odd_palindrome;
        }

        if (even_palindrome.length > res.length) {
            res = even_palindrome;
        }
    }

    return str.substr(res.start, res.length);
}

int main() {
    cout << longest("aabcdcb") << "\n";
    cout << longest("bananas") << "\n";

    return 0;
}

