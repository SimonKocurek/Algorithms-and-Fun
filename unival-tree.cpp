#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    vector<node*> children;

    node(int data) : data(data) {}
};

struct subtree_info {
    bool universal;
    int universal_subtrees;
};

subtree_info crawl(node* root) {
    int result = 0;

    bool all_same = true;
    for (auto child : root->children) {
        auto child_info = crawl(child);
        result += child_info.universal_subtrees;

        all_same = all_same && child_info.universal && child->data == root->data;
    }

    if (all_same) {
        result++;
    }

    return {all_same, result};
}

int universal_subtrees(node* root) {
    return crawl(root).universal_subtrees;
}

int main() {
    auto head = new node(1);
    head->children.push_back(new node(5));
    head->children.back()->children.push_back(new node(5));
    head->children.back()->children.push_back(new node(5));
    head->children.back()->children.back()->children.push_back(new node(5));
    head->children.push_back(new node(20));
    head->children.back()->children.push_back(new node(4));
    head->children.back()->children.back()->children.push_back(new node(8));
    head->children.back()->children.back()->children.back()->children.push_back(new node(8));
    head->children.back()->children.back()->children.back()->children.push_back(new node(8));
    head->children.back()->children.back()->children.back()->children.back()->children.push_back(new node(7));
    head->children.back()->children.back()->children.back()->children.back()->children.push_back(new node(8));

    cout << universal_subtrees(head) << "\n";

    return 0;
}

