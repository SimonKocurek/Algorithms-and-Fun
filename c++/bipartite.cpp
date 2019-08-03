#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int sets;
    cin >> sets;
    for (int i = 0; i < sets; ++i) {
        int stops, paths;
        cin >> stops >> paths;
        
        vector<int>* path[stops + 1];
        for (int j = 1; j < stops + 1; ++j) {
            path[j] = new vector<int>();
        }

        for (int j = 0; j < paths; ++j) {
            int from, to;
            cin >> from >> to;
            path[from]->push_back(to);
            path[to]->push_back(from);
        }

        unordered_set<int> black;
        unordered_set<int> unchecked;
        for (int j = 1; j < stops + 1; ++j) {
            unchecked.insert(j);
        }

        bool finished = false;
        while(!unchecked.empty() && !finished) {
            int current = *unchecked.begin();
            unchecked.erase(unchecked.begin());
            
            queue<int> searched;
            searched.push(current);
            black.insert(current);
           
           
            while(!searched.empty() && !finished) {
                int selected = searched.front();
                bool selected_black = black.find(selected) != black.end();
                searched.pop();

                for (auto& candidate : *(path[selected])) {
                    if (unchecked.find(candidate) == unchecked.end()) {
                        if (black.find(candidate) != black.end() && selected_black ||
                            black.find(candidate) == black.end() && !selected_black) {
                            finished = true;
                            break;
                        }

                        continue;
                    }

                    if (!selected_black) {
                        black.insert(candidate);
                    }

                    unchecked.erase(candidate);
                    searched.push(candidate);
                }
            }
            
        }

        if (!finished) {
            cout << "ANO\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}

