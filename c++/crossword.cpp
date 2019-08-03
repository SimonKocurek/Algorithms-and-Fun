#include <iostream>
#include <cstring>

#define WORD_COUNT 6

using namespace std;

char words[WORD_COUNT][3];

char crossword[3][3];
bool checked[6];

bool finished;

void print() {
    for (auto &word : crossword) {
        for (char character : word) {
            cout << character;
        }
        cout << '\n';
    }
}

bool valid_column(const int word_idx, const int column) {
    for (int i = 0; i < 3; ++i) {
        if (crossword[i][column] != words[word_idx][i]) {
            return false;
        }
    }

    return true;
}

void fill_column(const int idx) {
    if (idx == 3 || finished) {
        finished = true;
        return;
    }

    for (int j = 0; j < WORD_COUNT; ++j) {
        if (checked[j]) {
            continue;
        }

        if (valid_column(j, idx)) {
            checked[j] = true;
            fill_column(idx + 1);
            checked[j] = false;
        }
    }
}

void fill_line(const int idx) {
    if (idx == 3) {
        fill_column(0);
        return;
    }

    for (int j = 0; j < WORD_COUNT; ++j) {
        if (finished) {
            return;
        }

        if (checked[j]) {
            continue;
        }

        checked[j] = true;

        for (int i = 0; i < 3; ++i) {
            crossword[idx][i] = words[j][i];
        }
        fill_line(idx + 1);

        checked[j] = false;
    }
}

int main() {
    for (auto &word : words) {
        for (char &character : word) {
            cin >> character;
        }
    }

    qsort(words, sizeof(words) / 6, 6, (int (*)(const void *, const void *)) strcmp);

    fill_line(0);

    if (finished) {
        print();
    } else {
        cout << 0;
    }

    return 0;
}
