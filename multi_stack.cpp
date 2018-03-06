#include <bits/stdc++.h>

using namespace std;

template<class T>
class multi_stack {
    private:
        vector<stack<T>> stacks;
        uint32_t threshold;

    public:
        multi_stack(uint32_t threshold) : threshold(threshold) {}

        void push(T value) {
            if (!stacks.empty() && stacks.back().size() < threshold) {
                stacks.back().push(value);
            } else {
                stack<T> new_stack;
                new_stack.push(value);
                stacks.push_back(new_stack);
            }
        }

        T pop() {
            if (stacks.empty()) {
                throw;
            }

            auto result = stacks.back().top();
            stacks.back().pop();

            if (stacks.back().empty()) {
                stacks.pop_back();
            }

            return result;
        }

        T pop_at(int stack_idx) {
        }
};

int main() {
    multi_stack<int> test(3);
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);

    cout << test.pop() << "\n";
    cout << test.pop() << "\n";
    cout << test.pop() << "\n";
    cout << test.pop() << "\n";

    test.push(6);
    test.push(7);
    test.push(8);

    cout << test.pop() << "\n";
    cout << test.pop() << "\n";

    return 0;
}

