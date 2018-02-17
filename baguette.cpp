#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add_cheese(vector<int> &cheese) {
    int start, end;
    cin >> start >> end;
    
    cheese[start]++;
    if (end + 1 < cheese.size()) {
        cheese[end + 1]--;
    }
}

void print_cheese(vector<int> &cheese) { 
    int printed;
    cin >> printed;

    int current = 0;
    for (int i = 1; i <= printed; ++i) {
        current += cheese[i];
    }

    cout << current << '\n';
}

int main() {
    int size;
    cin >> size;
    
    vector<int> cheese(size + 1);
    
    int command;
    cin >> command;
    while (command != 0) {
        if (command == 1) {
            add_cheese(cheese);
        } else {
            print_cheese(cheese);
        }
        cin >> command;
    }

    return 0;
}

