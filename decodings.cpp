#include <bits/stdc++.h>

using namespace std;

void swap(int& a, int& b, int& c) {
    int temp = a;

    a = b;
    b = c;
    c = temp;
}

int decodings_of_pair(string s) {
    if (s[0] == '1') {
        return s[1] != '0' ? 2 : 1;
    } 

    if (s[0] == '2') {
        return s[1] >= '1' && s[1] <= '6' ? 2 : 1; 
    }

    return 1;
}

int decodings(string s) {
    if (s.length() <= 1) {
        return 1;
    }

    int first = 1;
    int second = decodings_of_pair(s);
    int last = - 1;

    for (unsigned int i = 0; i < s.length() - 2; ++i) {
        if (s[i + 1] == '1' && s[i + 2] != '0') {
            last = first + second;
        } else if (s[i + 1] == '2' && s[i + 2] >= '1' && s[i + 2] <= '6') {
            last = first + second;    
        } else {
            first = second;
            continue;
        }

        swap(first, second, last);
    }

    return max(second, last);
}

int main() {
    cout << decodings("111") << "\n";
    cout << decodings("") << "\n";
    cout << decodings("10") << "\n";
    cout << decodings("1234") << "\n";
    cout << decodings("172627") << "\n";
    cout << decodings("172026") << "\n";
    cout << decodings("11248") << "\n";

    return 0;
}

