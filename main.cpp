#include <iostream>
#include <vector>

using namespace std;

vector<string> words;
string content;

void read_input() {
    uint32_t word_count;
    cin >> word_count;

    words.reserve(word_count);
    for (auto& word : words) {
        cin >> word;
    }

    uint32_t bytes;
    cin >> bytes;
    char buffer[bytes];
    cin.read(buffer, bytes);

    content = string(buffer);
}

int main() {
    read_input();

    return 0;
}
