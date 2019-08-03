#include <bits/stdc++.h>

using namespace std;

bool CorrectBrackets(string& str) {
  vector<char> brackets(128, 0);
  brackets[')'] = '(';
  brackets['}'] = '{';
  brackets[']'] = '[';

  stack<char> seen;
  for (auto c : str) {
    if (brackets[c]) {
      if (seen.empty() || seen.top() != brackets[c]) {
        return false;
      }

      seen.pop();
    } else {
      seen.push(c);
    }
  }

  return seen.empty();
}

int main() {
  string a = "([])[]({})";
  string b = "([)]";
  string c = "((()";
  string d = "";

  cout << CorrectBrackets(a) << "\n";
  cout << CorrectBrackets(b) << "\n";
  cout << CorrectBrackets(c) << "\n";
  cout << CorrectBrackets(d) << "\n";

  return 0;
}

