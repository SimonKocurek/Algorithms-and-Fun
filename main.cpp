#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <locale>
#include <algorithm>
#include <iterator>

using namespace std;

int counter;
int min_window_start;
int min_window_end;

vector<string> content;
vector<string> words;
vector<bool> word_in_window;

void read_words() {
    uint32_t word_count;
    cin >> word_count;

    words.reserve(word_count);
    for (auto &word : words) {
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    word_in_window.reserve(word_count);
    fill(word_in_window.begin(), word_in_window.end(), false);
}

void read_content() {
    uint32_t bytes;
    cin >> bytes;
    char buffer[bytes];
    cin.read(buffer, bytes);

    auto paragraph = string(buffer);
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

    auto stream = istringstream{paragraph};
    copy(istream_iterator<string>(stream),
         istream_iterator<string>(),
         back_inserter(content));
}

void read_input() {
    read_words();
    read_content();
}

void find_window() {
    int window_start = 0;
    int window_end = 0;
    for (; window_start < content.size(); ++window_start) {

        auto find()
        if (find(words.begin(), words.end(), content_word) != words.end()) {
            counter++;
        }

        if (counter == words.size()) {

        }
    }
}

int main() {
    read_input();
    find_window();
    return 0;
}
