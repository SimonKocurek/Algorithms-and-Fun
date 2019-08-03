#include <bits/stdc++.h>

using namespace std;

template<class T>
class my_queue {
private:
    stack<T> in;
    stack<T> out;

public:
   T poll() {
       if (out.empty()) {
           while (!in.empty()) {
               out.push(in.top());
               in.pop();
           }
       }

       auto result = out.top();
       out.pop();
       return result;
   }

   void insert(T value) {
       in.push(value);
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

