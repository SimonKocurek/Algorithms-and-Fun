#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> values;
vector<long> tree;

void load_values() {
    int size;
    cin >> size;

    values = vector<int>(size + 1);
    for (int i = 1; i < size + 1; ++i) {
        int value;
        cin >> value;

        values[i] = value;
    }
}

int lowest_one_bit(int number) {
    return number & (-number); 
}

long prefix_sum(int index) {
    long sum = 0;

    while (index > 0) {
        sum += tree[index];
        index -= lowest_one_bit(index);
    }

    return sum;
}

void print(int start, int end) {
    cout << prefix_sum(end) - prefix_sum(start - 1) << "\n";
}

void change(int index, int value) {
    int change = value - values[index];
    values[index] = value;

    while (index < tree.size()) {
        tree[index] += change;
        index += lowest_one_bit(index);
    }
}

void create_fenwick_tree() {
    tree = vector<long>(values.size());

    for (int i = 1; i < tree.size(); ++i) {
        tree[i] = values[i] + prefix_sum(i - 1) - prefix_sum(i - lowest_one_bit(i));
    }
}

void execute_print() {
    int start, end;
    cin >> start >> end;

    print(start, end);
}

void execute_change() {
    int index, value;
    cin >> index >> value;

    change(index, value);
}

void process_instructions() {
    while (true) {
        int instruction_type;
        cin >> instruction_type;

        switch(instruction_type) {
            case 2:
                execute_print();
                break;
            case 1:
                execute_change();
                break;
            case 0:
                return;
        }
    }
}

int main() {
    load_values();
    create_fenwick_tree();
    process_instructions();
    return 0;
}

