#include <bits/stdc++.h>

using namespace std;

void guess() {
  int low, high, guesses;
  cin >> low >> high >> guesses;
  low++;

  string response;
  int middle;

  while (response != "CORRECT") {
    middle = (low + high) / 2;
    cout << middle << endl;
    cin >> response;

    if (response == "TOO_SMALL") {
      low = middle + 1;
    } else if (response == "TOO_BIG") {
      high = middle - 1;
    }
  }
}

int main() {
  int sets;
  cin >> sets;
  for (int i = 1; i <= sets; ++i) {
    guess();
  }
  return 0;
}

