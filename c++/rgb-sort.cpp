#include <bits/stdc++.h>

using namespace std;

void Sort(vector<char>& arr) {
  int r = 0;
  int g = 0;

  for (auto& c : arr) {
    switch (c) {
      case 'R':
        swap(c, arr[r++]);
      case 'G':
        swap(c, arr[g++]);
    }
  }
}

int main() {
  vector<char> arr {'G', 'B', 'R', 'R', 'B', 'R', 'G'};

  Sort(arr);
  for (auto& sorted : arr) {
    cout << sorted << " ";
  }
  cout << "\n";

  return 0;
}

