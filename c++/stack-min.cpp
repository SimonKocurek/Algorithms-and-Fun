#include <iostream>
#include <vector>

using namespace std;

template<class T>
class stack {
private:
    vector<T> minimums;
    vector<T> values;

public:
    void add(T value) {
        values.push_back(value);

        if (minimums.empty() || minimums.back() > value) {
            minimums.push_back(value);
        }
    }

    T pop() {
        auto result = values.back();
        values.pop_back();

        if (result == minimums.back()) {
            minimums.pop_back();
        }

        return result;
    }

    T minimum() {
        return minimums.back();
    }
};

int main() {
    stack<int> s;

    s.add(1);
    s.add(2);
    s.add(5);
    s.add(9);

    cout << s.pop() << endl;
    cout << s.minimum() << endl;

    s.add(-1);
    s.add(2);

    cout << s.minimum() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    s.add(-5);
    s.add(0);

    cout << s.minimum() << endl;
    return 0;
}

