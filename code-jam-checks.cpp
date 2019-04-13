#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sets;
	cin >> sets;

	for (int i = 1; i <= sets; ++i) {
		cout << "Case #" << i << ": ";

		string s;
		cin >> s;
		
		for (char c : s) {
			if (c == '4') {
				cout << 1;
			} else {
				cout << c;
			}
		}
		cout << " ";

		for (char c : s) {
			if (c == '4') {
				cout << 4;
			}
			else {
				cout << 0;
			}
		}

		cout << "\n";
	}

    return 0;
}
