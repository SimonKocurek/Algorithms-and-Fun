#include <bits/stdc++.h>

using namespace std;

struct node {
    int value;
    node *left;
    node *right;

    node(int value) : value(value) {}
};

void print(node *root, int level) {
    if (root->left != nullptr) {
        print(root->left, level + 1);
    }

    for (int i = 0; i < level; ++i) {
        cout << ' ';
    }
    cout << root->value << "\n";

    if (root->right != nullptr) {
        print(root->right, level + 1);
    }
}

void print(node *root) {
    print(root, 0);
}

int division_point(string serialized) {
    int seen = 0;

    for (size_t i = 0; i < serialized.length(); ++i) {
        if (serialized[i] == '(') {
            seen++;
        }

        if (serialized[i] == ')') {
            seen--;
        }

        if (seen == 0) {
            return i == 0 ? 0 : i + 1;
        }
    }

    return -1;
}

int number_len(string serialized) {
    for (size_t i = 1; i < serialized.length(); ++i) {
        if (serialized[i] == '(') {
            return i;
        }
    }
    return serialized.length();
}

node *deserialize(string serialized) {
    if (serialized.empty()) {
        return nullptr;
    }

    serialized = serialized.substr(1, serialized.length() - 2);

    auto division = division_point(serialized);
    node *left = deserialize(serialized.substr(0, division));

    serialized = serialized.substr(division);
    auto number_length = number_len(serialized);

    auto value = stoi(serialized.substr(0, number_length));
    node *head = new node(value);

    serialized = serialized.substr(number_length);
    node *right = deserialize(serialized);

    head->left = left;
    head->right = right;

    return head;
}

string serialize(node *root) {
    if (root == nullptr) {
        return "";
    }

    return "(" + serialize(root->left) + to_string(root->value) + serialize(root->right) + ")";
}

int main() {
    auto test = new node(10);
    test->left = new node(12);
    test->left->left = new node(5);
    test->left->right = new node(2);
    test->left->right->left = new node(4);
    test->right = new node(13);
    test->right->left = new node(18);

    cout << serialize(test) << "\n";
    print(deserialize(serialize(test)));

    return 0;
}

