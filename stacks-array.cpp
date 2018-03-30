#include <iostream>
#include <vector>

using namespace std;

template<class T>
class stacks {
    private:
        vector<int> top;
        vector<int> next;
        vector<T> values;

        int stack_count;
        int first_free;

    public:
        stacks(int stack_count) : stack_count(stack_count), first_free(-1) {
            top.resize(stack_count);
            fill(top.begin(), top.end(), -1);
        }

        void push(T value, int stack_id) {
            if (stack_id < 0 || stack_id >= stack_count) {
                throw;
            }

            if (first_free == values.size() - 1) {
                next.push_back(top[stack_id]);
                values.push_back(value);

                top[stack_id] = ++first_free;

            } else {
                auto next_first_free = next[first_free];

                next[first_free] = top[stack_id];
                values[first_free] = value;

                top[stack_id] = first_free;
                first_free = next_first_free;
            }
        }

        T pop(int stack_id) {
            if (stack_id < 0 || stack_id >= stack_count) {
                throw;
            }

            auto position = top[stack_id];
            if (position == -1) {
                throw;
            }
            top[stack_id] = next[position];

            auto result = values[position];

            next[position] = first_free;
            first_free = position;

            return result;
        }
};

int main() {
    stacks<int> multi_stack(3);
    multi_stack.push(1, 2);
    multi_stack.push(2, 2);
    multi_stack.push(3, 1);
    multi_stack.push(4, 0);
    multi_stack.push(5, 0);
    multi_stack.push(6, 0);
    multi_stack.push(7, 1);
    multi_stack.push(8, 0);
    multi_stack.push(9, 1);

    cout << multi_stack.pop(2) << endl;
    cout << multi_stack.pop(2) << endl;
    cout << endl;

    cout << multi_stack.pop(0) << endl;
    cout << multi_stack.pop(0) << endl;
    cout << multi_stack.pop(0) << endl;
    cout << multi_stack.pop(0) << endl;
    cout << endl;

    cout << multi_stack.pop(1) << endl;
    cout << multi_stack.pop(1) << endl;

    multi_stack.push(-1, 2);
    multi_stack.push(-2, 0);
    multi_stack.push(-3, 1);

    cout << multi_stack.pop(0) << endl;
    cout << multi_stack.pop(1) << endl;
    cout << multi_stack.pop(2) << endl;

    return 0;
}

