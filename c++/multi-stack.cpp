#include <bits/stdc++.h>

using namespace std;

template<class T>
class multi_stack {
    private:
        vector<vector<T>> stacks;
        uint32_t threshold;

    public:
        multi_stack(uint32_t threshold) : threshold(threshold) {}

        void push(T value) {
            if (!stacks.empty() && stacks.back().size() < threshold) {
                stacks.back().push_back(value);

            } else {
                vector<T> new_stack {value};
                stacks.push_back(new_stack);
            }
        }

        T pop() {
            if (stacks.empty()) {
                throw;
            }

            auto result = stacks.back().back();
            stacks.back().pop_back();

            if (stacks.back().empty()) {
                stacks.pop_back();
            }

            return result;
        }

        T pop_at(uint32_t stack_idx) {
            if (stacks.empty() || stack_idx < 0 || stack_idx + 1 > stacks.size()) {
                throw;
            }

            auto result = stacks[stack_idx].back();
            stacks[stack_idx].pop_back();

            while (stack_idx + 1 < stacks.size() && stacks[stack_idx].size() < threshold) {
                auto &current = stacks[stack_idx];
                auto &next = stacks[stack_idx + 1];

                auto value = next.front();
                next.erase(next.begin());
                current.push_back(value);

                if (next.empty()) {
                    stacks.pop_back();
                }

                stack_idx++;
            }

            return result;
        }

        void print() {
            cout << '\n' << "Stack:" << '\n';
            for (auto sub_stack : stacks) {
                for (auto value : sub_stack) {
                    cout << value << " ";
                }
                cout << '\n';
            }
            cout << '\n';
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

    test.print();

    multi_stack<int> test2(2);
    test2.push(1);
    test2.push(2);
    test2.push(3);
    test2.push(4);
    test2.push(5);

    cout << test2.pop_at(0) << "\n";
    cout << test2.pop_at(1) << "\n";
    cout << test2.pop_at(0) << "\n";
    cout << test2.pop() << "\n";

    test2.push(6);
    test2.push(7);
    test2.push(8);

    test2.print();
    cout << test2.pop_at(1) << "\n";
    cout << test2.pop_at(0) << "\n";

    return 0;
}

