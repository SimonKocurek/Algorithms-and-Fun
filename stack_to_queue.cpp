#include <bits/stdc++.h>

using namespace std;

template<class T>
class my_queue {
private:
    stack<T> values;
    stack<T> mover;

public:
   T poll() {
       auto result = values.top();
       values.pop();
       return result;
   }

   void insert(T value) {
       while (!values.empty()) {
           mover.push(values.top());
           values.pop();
       }

       values.push(value);

       while (!mover.empty()) {
           values.push(mover.top());
           mover.pop();
       }
   }
};

int main() {
    my_queue<int> test;
    test.insert(1);
    test.insert(2);
    test.insert(4);
    test.insert(8);

    cout << test.poll() << "\n";
    cout << test.poll() << "\n";

    test.insert(16);
    test.insert(32);

    cout << test.poll() << "\n";
    cout << test.poll() << "\n";
    cout << test.poll() << "\n";

    return 0;
}

