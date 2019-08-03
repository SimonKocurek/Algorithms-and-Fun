#include <iostream>

using namespace std;

void refresh_window(int &start, int &end, int current, string &blob) {
  start = current;
  end = current;

  while(true) {
    if (end >= blob.length() || blob[end - start] != blob[end]) {
     break;
    }

    end++;
  }
}

void set_window_z(int &start, int &end, int current, string &blob, int *z) {
  int pattern_index = current - start;
  int distance_from_end = end - current + 1;

  if (z[pattern_index] < distance_from_end) {
    z[current] = z[pattern_index];
  } else {
    int next = end + 1;
    while(next < blob.length() && blob[next] == blob[next - current]) {
      next++;
    }

    z[current] = next - current;
    start = current;
    end = next - 1;
  }
}

int main() {
  string pattern;
  string content;

  cin >> pattern >> content;

  string blob = pattern + "$" + content;
  int z[blob.length()]{0};

  int window_start = 0;
  int window_end = 0;
  for (int i = 1; i < blob.length(); ++i) {

    if (i > window_end) {
      refresh_window(window_start, window_end, i, blob);
      z[i] = window_end - window_start;
    } else {
      set_window_z(window_start, window_end, i, blob, z);
    }
  }

  for (int i = pattern.length(); i < blob.length(); ++i) {
    if (z[i] == pattern.length()) {
      cout << "Found at index: " << i - pattern.length() - 1 << '\n';
    }
  }

  return 0;
}

