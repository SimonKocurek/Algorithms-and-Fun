#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sets;
	cin >> sets;

	for (int i = 1; i <= sets; ++i) {
		cout << "Case #" << i << ": ";

		int n;
		cin >> n;
		
		char c;
		cin.get();
		while ((c = cin.get()) != '\n' && c != EOF) {
			if (c == 'E') {
				cout << 'S';
			}
			else {
				cout << 'E';
			}
		}
		cout << "\n";
	}

    return 0;
}
