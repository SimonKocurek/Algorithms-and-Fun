#include <bits/stdc++.h>

using namespace std;

vector<string> Justify(vector<string>& words, int length) {
  vector<string> result;

  string added;
  for (auto& word : words) {
    if (!added.empty()) {
      added += word;
    }

    if (added.length() >= length()) {
      result.push_back(added);
      added.clear();
    }

  }

  return result;
}

int main() {
  return 0;
}

