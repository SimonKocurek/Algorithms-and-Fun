#include <bits/stdc++.h>

using namespace std;

vector<int> multiplications(vector<int> &original) {
    vector<int> result(original.size());

    if (original.size() < 2) {
        fill(original.begin(), original.end(), 0);
        return result;
    }

    vector<int> prefixes(original.size());
    prefixes[0] = original[0];
    for (auto i = 1; i < prefixes.size(); ++i) {
        prefixes[i] = prefixes[i - 1] * original[i];
    }

    vector<int> sufixes(original.size());
    sufixes[sufixes.size() - 1] = original.back();
    for (int i = sufixes.size() - 2; i >= 0; --i) {
        sufixes[i] = sufixes[i + 1] * original[i];
    }

    result[0] = sufixes[1];
    for (auto i = 1; i < original.size() - 1; ++i) {
        result[i] = prefixes[i - 1] * sufixes[i + 1];
    }
    result[original.size() - 1] = prefixes[original.size() - 2];

    return result;
}

void print_result(vector<int> &tested) {
    for (auto number : multiplications(tested)) {
        cout << number << " ";
    }
    cout << '\n';
}

int main() {
    vector<int> a {1, 2, 3, 4, 5};
    vector<int> b {3, 2, 1};
    vector<int> c {};
    vector<int> d {1};
    vector<int> e {1, 2, 3, 4, 5, 2};

    print_result(a);
    print_result(b);
    print_result(c);
    print_result(d);
    print_result(e);

    return 0;
}

