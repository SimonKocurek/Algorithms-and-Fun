#include <bits/stdc++.h>

using namespace std;

void initialize_tree(vector<vector<int>>& tree, int leaves) {
    int row_size = 1;
    while (true) {
        vector<int> row(row_size, 0);
        tree.push_back(row);

        if (row_size >= leaves) {
            break;
        }

        row_size *= 2;
    }
}

void fill_tree(vector<vector<int>>& tree, int leaves) {
    auto& last = tree.back();
    for (int i = 0; i < leaves; ++i) {
        cin >> last[i];
    }

    for (int i = tree.size() - 2; i >= 0; --i) {
        for (int j = 0; j < tree[i].size(); ++j) {
            tree[i][j] = max(tree[i + 1][j * 2], tree[i + 1][j * 2 + 1]);
        }
    }
}

void build_tree(vector<vector<int>>& tree, int leaves) {
    initialize_tree(tree, leaves);
    fill_tree(tree, leaves);
}

void change(vector<vector<int>>& tree, int index, int value) {
    index--;
    tree.back()[index] = value;

    for (int i = tree.size() - 2; i >= 0; --i) {
        index /= 2;
        tree[i][index] = max(tree[i + 1][index * 2], tree[i + 1][index * 2 + 1]);
    }
}

int get_max(vector<vector<int>>& tree, int start, int end) {
    int result = max(tree.back()[start], tree.back()[end]);

    for (int i = tree.size() - 1; i >= 0; --i) {
        if (start / 2 == end / 2) {
            break;
        }

        if (start % 2 == 0) {
            result = max(result, tree[i][start + 1]);
        }
        if (end % 2 == 1) {
            result = max(result, tree[i][end - 1]);
        }

        start /= 2;
        end /= 2;
    }

    return result;
}

void print(vector<vector<int>>& tree, int start, int end) {
    cout << get_max(tree, start - 1, end - 1) << endl;
}

void process_commands(vector<vector<int>>& tree) {
    int command;
    cin >> command;

    while (command != 0) {
        int start, end;
        cin >> start >> end;

        switch(command) {
            case 1:
            change(tree, start, end);
            break;

            case 2:
            print(tree, start, end);
            break;
        }

        cin >> command;
    }
}

int main() {
    int count;
    cin >> count;

    vector<vector<int>> tree;
    build_tree(tree, count);
    process_commands(tree);

    return 0;
}
