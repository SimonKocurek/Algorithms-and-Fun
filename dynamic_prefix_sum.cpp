#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

auto load_input() {
    int size;
    cin >> size;

    vector<int> result(size);
    for (int i = 0; i < size; ++i) {
        int value;
        cin >> value;

        result[i] = value;
    }

    return result;
}

auto create_fenwick_tree(vector<int> &values) {
    vector<int> result(values.size());

    return result;
}

void execute_print(vector<int> &tree) {

}

void execute_change(vector<int> &tree) {
}

void process_instructions(vector<int> &tree) {
    while (true) {
        int instruction_type;
        cin >> instruction_type;

        switch(instruction_type) {
            case 2:
                execute_print(tree);
                break;
            case 1:
                execute_change(tree);
                break;
            case 0:
                return;
        }
    }
}

int main() {
    auto values = load_input();
    auto tree = create_fenwick_tree(values);
    process_instructions();
    return 0;
}

