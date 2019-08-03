#include <iostream>

using namespace std;

bool is_digit(char c);

int parse_number(string::iterator &start);

string parse_sub_expression(string::iterator &start);

string decompress_sub_expression(string::iterator &start);

char decompress_character(string::iterator &start);

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int parse_number(string::iterator &start) {
    auto number = 0;

    while (*start != '[') {
        number *= 10;
        number += *start - '0';
        start++;
    }

    return number;
}

string parse_sub_expression(string::iterator &start) {
    start++;
    string result;

    while (*start != ']') {
        if (is_digit(*start)) {
            result += decompress_sub_expression(start);
        } else {
            result += decompress_character(start);
        }
    }

    start++;

    return result;
}

string decompress_sub_expression(string::iterator &start) {
    string result;

    auto digit = parse_number(start);
    auto repeated = parse_sub_expression(start); 

    for (auto i = 0; i < digit; ++i) {
        result += repeated;
    }

    return result;
}

char decompress_character(string::iterator &start) {
    auto c = *start;
    start++;
    return c;
}

string decompress(string::iterator start, string::iterator end) {
    string result;

    while (start !=  end) {
        if (is_digit(*start)) {
            result += decompress_sub_expression(start);
        } else {
            result += decompress_character(start);
        }
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

