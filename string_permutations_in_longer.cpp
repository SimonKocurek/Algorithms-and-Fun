#include <iostream>

const int char_limit = 256;

void print_result(std::string longer, int start, int end) {
    for (int i = start; i < end; ++i) {
        std::cout << longer[i];
    }
    std::cout << '\n';
}

void print_permutations(std::string longer, std::string shorter) {
    int zeros = char_limit;
    int character_count[char_limit] = {0};
    
    for (auto character : shorter) {
        zeros -= character_count[character] == 0;
        character_count[character]++;
    }

    for (int i = 0; i < longer.length(); ++i) {
        int removed = i - shorter.length();
        if (removed >= 0) {
            zeros -= character_count[longer[removed]] == 0;
            character_count[longer[removed]]++;
            zeros += character_count[longer[removed]] == 0;
        }

        zeros -= character_count[longer[i]] == 0;
        character_count[longer[i]]--;
        zeros += character_count[longer[i]] == 0;

        if (zeros == char_limit) {
            print_result(longer, i - shorter.length() + 1,  i + 1);
        }
    }
}

int main() {
    print_permutations("cbabadcbbabbcbabaabccbabc", "abbc");
    return 0;
}

