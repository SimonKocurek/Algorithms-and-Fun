#include <iostream>

using namespace std;

string input;
string pattern;

void optimize_wildcards() {
  auto index = 0;
  while (true) {
    index = pattern.find("**", index);

    if (index == string::npos) {
      break;
    }

    pattern.replace(index, 2, "*");
  }
}

void find_if_matching() {
  bool matches[input.length() + 1][pattern.length() + 1];
  for (auto &line : matches) {
    for (auto &matches : line) {
      matches = false;
    }
  }


  matches[0][0] = true;
  matches[0][1] = pattern[0] == '*';

  for (int input_idx = 0; input_idx < input.length(); ++input_idx) {
    for (int pattern_idx = 0; pattern_idx < pattern.length(); ++pattern_idx) {
      if (pattern[pattern_idx] == '?' || input[input_idx] == pattern[pattern_idx]) {
        matches[input_idx + 1][pattern_idx + 1] = matches[input_idx][pattern_idx];
        continue;
      }

      if (pattern[pattern_idx] == '*') {
        matches[input_idx + 1][pattern_idx + 1] = matches[input_idx][pattern_idx + 1] ||
          matches[input_idx + 1][pattern_idx];
      }
    }
  }

  if (matches[input.length()][pattern.length()]) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
}

int main() {
  int sets;
  cin >> sets;

  for (int i = 0; i < sets; ++i) {
    cin >> pattern >> input;

    optimize_wildcards();
    find_if_matching();
  }

  return 0;
}

