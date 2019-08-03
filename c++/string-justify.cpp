#include <bits/stdc++.h>

using namespace std;

typedef pair<vector<string>, int> Line;

vector<Line> Pack(vector<string>& words, int length) {
  vector<Line> result;

  Line next = {vector<string>(), 0};
  for (auto& word : words) {
    if (next.first.size() + next.second + word.size() <= length) {
      next.second += word.size();
      next.first.push_back(word);

    } else {
      result.push_back(next);

      next.first.clear();
      next.first.push_back(word);
      next.second = word.size();
    }
  }

  if (!next.first.empty()) {
    result.push_back(next);
  }

  return result;
}

string Printed(Line& line, int length) {
  string result;

  if (line.first.size() == 1) {
    result = line.first.back();

    for (int i = result.size(); i < length; ++i) {
      result += ' ';
    }

  } else {
    auto spaces_per_word = (length - line.second) / (line.first.size() - 1);
    auto additional_spaces = (length - line.second) % (line.first.size() - 1);

    for (int i = 0; i < line.first.size() - 1; ++i) {
      result += line.first[i];

      for (int j = 0; j < spaces_per_word; ++j) {
        result += ' ';
      }

      if (additional_spaces) {
        additional_spaces--;
        result += ' ';
      }
    }

    result += line.first.back();
  }

  return result;
}

vector<string> Justify(vector<string>& words, int length) {
  vector<string> result;

  auto lines = Pack(words, length);
  for (auto& line : lines) {
    auto printed = Printed(line, length);
    result.push_back(printed);
  }

  return result;
}

int main() {
  vector<string> words {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  int length = 16;

  for (auto& line : Justify(words, length)) {
    cout << line << "\n";
  }

  return 0;
}

