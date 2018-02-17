#include <iostream>

using namespace std;

bool chars_edited(string a, string b, int edited) {
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            edited--;
        }
        
        if (edited < 0) {
            return false;
        }
    }
    return true;
}

bool one_removed(string longer, string shorter) {
    int i = 0;
    int j = 0;

    int removed = 0;
    while (i < longer.length() && j < shorter.length()) {
        if (longer[i] != shorter[j]) {
            i++;
            removed++;

            if (removed > 1) {
                return false;
            }
        } else {
            i++;
            j++;
        }
    }

    return true;
}

bool one_away(string a, string b) {
    if (a.length() == b.length()) {
        return chars_edited(a, b, 1);
    }

    if (a.length() < b.length()) {
        swap(a, b);
    }

    if (a.length() - b.length() > 1) {
        return false;
    }
    return one_removed(a, b);
}

int main() {
    cout << one_away("abc", "abc") << '\n';
    cout << one_away("test", "tet") << '\n';
    cout << one_away("dac", "aco") << '\n';
    cout << one_away("dac", "daco") << '\n';
    cout << one_away("abcee", "abcde") << '\n';

    return 0;
}

