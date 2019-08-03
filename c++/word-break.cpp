#include <bits/stdc++.h>

using namespace std;

typedef vector<string> Dictionary;

void InsertIfMatched(vector<Dictionary>& result, string& matched, int i, string& word) {
  if (!result[i].empty() && word.compare(i, matched.length(), matched) == 0) {
    result[i + matched.length()].push_back(matched);
  }
}

Dictionary Reconstruct(vector<Dictionary>& table) {
  Dictionary result;

  int i = table.size() - 1;
  while (i > 0) {
    auto& dict = table[i];
    if (dict.empty()) {
      throw;
    }

    auto& taken = dict.front();
    result.push_back(taken);
    i -= taken.length();
  }

  return result;
}

Dictionary WordBreak(Dictionary& dictionary, string& word) {
  vector<Dictionary> result(word.length() + 1);
  result[0].emplace_back();

  for (int i = 0; i < word.length(); ++i) {
    for (auto& w : dictionary) {
      InsertIfMatched(result, w, i, word);
    }
  }

  return Reconstruct(result);
}

void Print(Dictionary dictionary) {
  for (auto& word : dictionary) {
    cout << word << " ";
  }
  cout << "\n";
}

int main() {
  Dictionary a {"quick", "the", "brown", "fox"};
  Dictionary b {"bed", "bath", "bedbath", "and", "beyond"};
  Dictionary c {"ac", "a", "ca"};

  string a_word = "thequickbrownfox";
  string b_word = "bedbathandbeyond";
  string c_word = "acaca";

  Print(WordBreak(a, a_word));
  Print(WordBreak(b, b_word));
  Print(WordBreak(c, c_word));

  return 0;
}

