#include <bits/stdc++.h>

using namespace std;

struct node {
    node* chars[27];
    bool last;
};

void add_character(node* root, string& word, int idx) {
    if (idx == word.length()) {
        root->last = true;
        return;
    }

    auto& next_node = root->chars[word[idx] - 'a'];
    if (next_node == nullptr) {
        next_node = new node;
    }
    add_character(next_node, word, idx + 1);
}

void add_word(node* root, string& word) {
    add_character(root, word, 0);
}

node* build_tree(vector<string>& dictionary) {
    node* tree = new node;
    for (auto& word : dictionary) {
        add_word(tree, word);
    }
    return tree;
}

node* move_to_prefix_root(node* root, string& searched) {
    for (auto character : searched) {
        if (root == nullptr) {
            break;
        }

        root = root->chars[character - 'a'];
    }

    return root;
}

void fill_reachable(node* root, string str, vector<string>& results) {
    if (root == nullptr) {
        return;
    }

    if (root->last) {
        results.push_back(str);
    }

    for (int i = 0; i < 27; ++i) {
        char new_char = 'a' + i;
        fill_reachable(root->chars[i], str + new_char, results);
    }
}

vector<string> get_possibilities(node* root, string searched) {
    vector<string> result;

    auto prefix_root = move_to_prefix_root(root, searched);
    fill_reachable(prefix_root, searched, result);

    return result;
}

int main() {
    vector<string> dictionary {"te", "test", "testa", "tesz", "testzasd", "testb", "tes", "ga", "gadf", "testhgd"};
    auto tree = build_tree(dictionary);

    for (auto result : get_possibilities(tree, "test")) {
        cout << result << " ";
    }
    cout << "\n";

    return 0;
}
