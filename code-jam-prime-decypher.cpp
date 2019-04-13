#include <bits/stdc++.h>

using namespace std;

bool construct(vector<int>& constructed, vector<unordered_map<int, int>>& pairs, int started, int id, unordered_set<int>& seen) {
	if (seen.size() >= ('Z' - 'A') && seen.find(started) != seen.end()) {
		return false;
	}

	if (id >= pairs.size()) {
		constructed.push_back(started);
		return true;
	}

	auto& p = pairs[id];
	if (p.find(started) != p.end()) {
		constructed.push_back(started);
		if (construct(constructed, pairs, p[started], id + 1, seen)) {
			return true;
		}

		constructed.pop_back();
	}
	return false;
}

bool construct(vector<int>& constructed, vector<unordered_map<int, int>>& pairs) {
	unordered_set<int> seen;

	for (auto& mp : pairs[0]) {
		constructed.push_back(mp.first);
		seen.insert(mp.first);

		if (construct(constructed, pairs, mp.second, 1, seen)) {
			return true;
		}

		seen.erase(constructed.back());
		constructed.pop_back();
	}

	return false;
}

void build_translation(vector<int>& constructed, unordered_map<int, char>& translation) {
	set<int> a;
	for (auto val : constructed) {
		a.insert(val);
	}

	int c = 'A';
	for (auto val : a) {
		translation[val] = c;
		c++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sets;
	cin >> sets;

	for (int i = 1; i <= sets; ++i) {
		cout << "Case #" << i << ": ";

		int n, v;
		cin >> n >> v;
		vector<int> values(v);
		for (auto& val : values) {
			cin >> val;
		}

		vector<bool> is_prime(n + 1, true);
		for (int j = 2; j < n; ++j) {
			if (is_prime[j]) {
				for (int k = j * 2; k <= n; k += j) {
					is_prime[k] = false;
				}
			}
		}

		vector<int> primes;
		unordered_set<int> seen;
		for (int j = 2; j <= n; ++j) {
			if (is_prime[j]) {
				seen.insert(j);
				primes.push_back(j);
			}
		}
		
		vector<unordered_map<int, int>> pairs(v);
		for (int j = 0; j < values.size(); ++j) {
			auto val = values[j];
			auto& a = pairs[j];

			for (auto prime : primes) {
				if (val % prime == 0 && seen.find(val / prime) != seen.end()) {
					a[prime] = val / prime;
					a[val / prime] = prime;
				}
			}
		}

		vector<int> constructed;
		construct(constructed, pairs);

		unordered_map<int, char> translation;
		build_translation(constructed, translation);

		for (auto val : constructed) {
			cout << translation[val];
		}
		cout << "\n";
	}

    return 0;
}
