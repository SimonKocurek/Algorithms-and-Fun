#include <bits/stdc++.h>

using namespace std;

string Decode(string in) {
  string out;

  int i = 0;
  while (i < in.size()) {
    int count = 0;
    while (in[i] >= '0' && in[i] <= '9') {
      count *= 10;
      count += in[i++] - '0';
    }

    char seen = in[i++];

    for (int j = 0; j < count; ++j) {
      out += seen;
    }
  }

  return out;
}

string Encode(string in) {
  if (in.empty()) {
    return "";
  }

  string out;

  int count = 1;
  char seen = in[0];
  for (int i = 1; i < in.size(); ++i) {
    if (in[i] == seen) {
      count++;
    } else {
      out += to_string(count);
      out += seen;

      count = 1;
      seen = in[i];
    } 
  }

  out += to_string(count);
  out += seen;

  return out;
}

int main() {
  cout << (Encode("AAAABBBCCCCCCCCCCCDAA") == "4A3B11C1D2A") << "\n";
  cout << (Decode("10A3B2C1D2A") == "AAAAAAAAAABBBCCDAA") << "\n";

  return 0;
}

