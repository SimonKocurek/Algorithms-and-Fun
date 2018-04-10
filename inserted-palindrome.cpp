#include <bits/stdc++.h>

using namespace std;

const int alphabet = 'z' - 'a' + 1;

bool IsPalindrome(string& s) {
  int start = 0;
  int end = s.size() - 1;

  while (start < end) {
    if (s[start++] != s[end--]) {
      return false;
    }
  }

  return true;
}

string Changed(string original) {
  if (IsPalindrome(original)) {
    return original;
  }

  bool characters[alphabet] = {};
  for (auto c : original) {
    characters[c - 'a'] = true;
  }

  unordered_set<string> seen;
  queue<string> next;
  seen.insert(original);
  next.push(original);

  while (!next.empty()) {
    auto current = next.front();
    next.pop();

    for (int i = 0; i <= current.size(); ++i) {
      for (int j = 0; j < alphabet; ++j) {
        if (characters[j]) {
          auto copy = current;
          copy.insert(i, 1, j + 'a');

          if (IsPalindrome(copy)) {
            return copy;
          }

          if (seen.find(copy) == seen.end()) {
            seen.insert(copy);
            next.push(copy);
          }
        }
      }
    }
  }

  throw;
}

int main() {
  cout << Changed("race") << " ecarace" << "\n";
  cout << Changed("google") << " elgoogle" << "\n";
  cout << Changed("ab") << " bab" << "\n";
  cout << Changed("aa") << " aa" << "\n";
  cout << Changed("abcd") << " dcbabcd" << "\n";
  cout << Changed("abcda") << " adcbcda" << "\n";
  cout << Changed("abcde") << " edcbabcde" << "\n";

  return 0;
}

