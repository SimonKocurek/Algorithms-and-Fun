#include <bits/stdc++.h>

using namespace std;

int spaces(string& str, int true_length) {
    int result = 0;
    for (int i = 0; i < true_length; ++i) {
        result += str[i] == ' ';
    }
    return result;
}

void urlify(string& str, int true_length) {
    int offset = spaces(str, true_length) * 2;

    for (int i = str.length() - 1; i >= 0; --i) {
        str[i] = str[i - offset];

        if (str[i] == ' ') {
            str[i] = '0';
            str[i - 1] = '2';
            str[i - 2] = '%';

            i -= 2;
            offset -= 2;
        }
    }
}

int main() {
    string s = "Mr John Smith    ";
    urlify(s, 13);
    cout << s << "\n";

    return 0;
}

