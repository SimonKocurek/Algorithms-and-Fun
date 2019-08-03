#include <iostream>
#include <unordered_set>

using namespace std;

struct subset {
    unordered_set<int> items;
};

template<>
struct hash<subset> {
    inline size_t operator()(const subset& a) const {
        return a.items.size();
    }
};

inline bool operator==(const subset& a, const subset& b) {
    if (a.items.size() != b.items.size()) {
        return false;
    }

    for (auto i = a.items.begin(); i != a.items.end(); ++i) {
        if (b.items.find(*i) == b.items.end()) {
            return false;
        }
    }

    return true;
}

static bool* taken;
static int* elements;
static int size;
static unordered_set<subset> result;

void print_subset(const subset& printed) {
    for (auto& item : printed.items) {
        cout << item << " ";
    }
    cout << '\n';
}

void add_subset() {
    subset added;

    for (int i = 0; i < size; ++i) {
        if (!taken[i]) {
            continue;
        }

        added.items.insert(elements[i]);
    }

    result.insert(added);
}

void get_all_subsets(int start) {
    if (start == size) {
        add_subset();
        return;
    }

    taken[start] = true;
    get_all_subsets(start + 1);
    taken[start] = false;
    get_all_subsets(start + 1);
}

int main() {
    cin >> size;

    taken = new bool[size]{0};
    elements = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> elements[i];
    }

    get_all_subsets(0);
    
    for (auto& result_subset : result) {
        print_subset(result_subset);
    }

    return 0;
}

