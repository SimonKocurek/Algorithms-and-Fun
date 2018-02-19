#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree {
    int start;
    int end;
    long value = 0;
    tree *left;
    tree *right;

    tree(int start, int end) : start(start), end(end) {}
};

void add_layer(tree *values, int start, int end) {
    if (start == values->start && end == values->end) {
        values->value++;
        return;
    }

    if (start >= values->left->start && end <= values->left->end) {
        add_layer(values->left, start, end);
        return;
    }

    if (start >= values->right->start && end <= values->right->end) {
        add_layer(values->right, start, end);
        return;
    }

    add_layer(values->left, start, values->left->end);
    add_layer(values->right, values->right->start, end);
}

void add_cheese(tree *values) {
    int start, end;
    cin >> start >> end;

    add_layer(values, start, end);
}

long get_overlaps(tree *values, int index) {
    long sum = 0;

    auto current = values;
    while(current->start != index || current->end != index) {
        sum += current->value;

        if (index <= current->left->end) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return sum + current->value;
}

void print_cheese(tree *values) { 
    int printed;
    cin >> printed;

    cout << get_overlaps(values, printed) << '\n';
}

tree *initialize_tree(int start, int end) {
    tree *values = new tree(start, end);

    if (start == end) {
        return values;
    }

    int middle = (start + end) / 2;

    values->left = initialize_tree(start, middle);
    values->right = initialize_tree(middle + 1, end);

    return values;
}

int main() {
    int size;
    cin >> size;

    tree *values = initialize_tree(1, size);

    int command;
    cin >> command;
    while (command != 0) {
        if (command == 1) {
            add_cheese(values);
        } else {
            print_cheese(values);
        }
        cin >> command;
    }

    return 0;
}

