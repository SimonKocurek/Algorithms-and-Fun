#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node {
    vector<int> ch;
    bool visited = false;
};

int nonvisited;

void traverse(node& a, vector<node>& nd, int anded, ll& max, int path) {
    max = std::max(max, anded * (ll)path);

    for (int c : a.ch) {
        if (nd[c].visited || c & anded * nonvisited <= max) {
            continue;
        }
        
        nonvisited--;
        nd[c].visited = true;
        traverse(nd[c], nd, anded & c, max, path + 1);
        nd[c].visited = false;
        nonvisited++;
    }
}

int main() {
    int sets;
    cin >> sets;
    for (int i = 0; i < sets; ++i) {
        int nodes;
        cin >> nodes;

        nonvisited = nodes - 1;
        vector<node> nd(nodes + 1);
        for (int j = 0; j < nodes - 1; ++j) {
            int fr, to;
            cin >> fr >> to;

            nd[fr].ch.push_back(to);
            nd[to].ch.push_back(fr);
        }

        ll max = 0;
        for (int j = 0; j < nd.size(); ++j) {
            nd[j].visited = true;
            traverse(nd[j], nd, j, max, 1);
            nd[j].visited = false;
        }

        cout << max << "\n";
    }
    return 0;
}