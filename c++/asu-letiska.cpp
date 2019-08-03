#include <bits/stdc++.h>

int visited(int got, vector<vector<bool>>& edge, vector<bool>& seen, int current, int starters) {
    seen[current] = true;
    int result = -1;

    if (current < starters) {
        result = got;
    }

    for (int i = 0; i < edge.size(); ++i) {
        if (!seen[i] && edge[current][i]) {
            result = max(result, visited(got + 1, edge, seen, i, starters));
        }
    }

    seen[current] = false;
    return result;
}

int main() {
    int vertices, starters, edges;
    cin >> vertices >> starters >> edges;

    vector<vector<bool>> edge(vertices, vector<bool>(vertices, false));

    for (int i = 0; i < edge; ++i) {
        int from, to;
        cin >> from >> to;

        edge[from][to] = true;
        edge[to][from] = true;
    }

    vector<bool> seen(vertices, false);
    int result = 0;
    for (int i = 0; i < starters; ++i) {
        result = max(result, visited(1, edge, seen, i, starters));
    }
    cout << result << endl;
    return 0;
}
