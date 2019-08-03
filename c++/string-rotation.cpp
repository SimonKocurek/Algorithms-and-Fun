#include <iostream>
#include <string>

using namespace std;

bool is_substring(string a, string b) {
    return a.find(b) != string::npos;
}

bool string_rotation(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }

    if (a.length() == 0) {
        return true;
    }

    int delimiter = 0;
    while (delimiter < a.length()) {
        if (a[delimiter] == b[0]) {
            break;
        }
        delimiter++;
    }

    a = a.substr(delimiter) + a.substr(0, delimiter);
    return is_substring(a, b);
}

int main() {
    cout << string_rotation("abcdef", "abc") << "\n";
    cout << string_rotation("abcdef", "cdefab") << "\n";
    cout << string_rotation("abcdef", "cdefba") << "\n";
    cout << string_rotation("abcdef", "efabcd") << "\n";
    cout << string_rotation("waterbottle", "erbottlewat") << "\n";

    return 0;
}

