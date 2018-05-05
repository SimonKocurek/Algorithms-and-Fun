#include <bits/stdc++.h>

using namespace std;

const int alphabeth = 'Z' - 'A' + 1;

void Solve() {
    int word_count, length;
    cin >> word_count >> length;

    vector<vector<bool>> used_character(length, vector<bool>(alphabeth, false));

    unordered_set<string> words;
    for (int i = 0; i < word_count; ++i) {
        string word;
        cin >> word;

        words.insert(word);

        for (int j = 0; j < length; ++j) {
            int c = word[j] - 'A';
            used_character[j][c] = true;
        }
    }

    if (length <= 1) {
        cout << "-";
        return;
    }

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < alphabeth; ++j) {
            if (!used_character[i][j]) {
                continue;
            }

            for (auto word : words) {
                word[i] = j + 'A';

                if (words.find(word) == words.end()) {
                    cout << word;
                    return;
                }
            }
        }
    }

    cout << "-";
}

int main() {
    int tests;
    cin >> tests;

    for (int i = 1; i <= tests; ++i) {
        cout << "Case #" << i << ": ";
        Solve();
        cout << "\n";
    }

    return 0;
}
