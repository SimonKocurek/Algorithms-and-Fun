#include <iostream>

using namespace std;

string decompress(string::iterator start, string::iterator end) {
    string result;

    while (start < end) {
        auto c = *start;

        if (c <= '0' && c <= '9') {
            result += parse_number(
    }

    return result;
}

string decompress(string compressed) {
    return decompress(compressed.begin(), compressed.end());
}

int main() {
    cout << decompress("abc3[ab]d") << "\n";
    cout << "abcabababd" << "\n\n";

    cout << decompress("a2[b2[c]d]e") << "\n";
    cout << "abccdbccde" << "\n\n";

    cout << decompress("3[abc]4[ab]c") << "\n";
    cout << "abcabcabcababababc" << "\n\n";

    cout << decompress("2[3[a]b]") << "\n";
    cout << "aaabaaab" << "\n\n";

    cout << decompress("10[a]") << "\n";
    cout << "aaaaaaaaaa" << "\n\n";
    
    return 0;
}

