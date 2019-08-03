/*
   This problem was asked by Twitter.

   You run an e-commerce website and
   want to record the last N order ids
   in a log. Implement a data structure
   to accomplish this, with the following API:

   record(order_id): adds the order_id
   to the log

   get_last(i): gets the ith last element
   from the log. i is guaranteed to be
   smaller than or equal to N.

   You should be as efficient with time and space as possible.
 */

#include <bits/stdc++.h>

using namespace std;

class circular_array {
    private:
        vector<int> data;
        uint32_t start;
        uint32_t size;

    public:
        circular_array(uint32_t size) : start(-1), size(size) {
            data.reserve(size);
        }

        void record(int id) {
            if (data.size() == size) {
                start = (start + 1) % size;
                data[start] = id;
            } else {
                data.push_back(id);
            }
        }

        int get_last(int index_from_end) {
            if (data.size() == size) {
                if (index_from_end >= size) {
                    throw;
                }
                int index = start - index_from_end;
                if (index < 0) {
                    index = size + index;
                }

                return data[index];

            } else {
                if (data.size() - index_from_end - 1 < 0) {
                    throw;
                }
                return data[data.size() - index_from_end - 1];
            }
        }

};

int main() {
    circular_array test(5);
    test.record(1);
    test.record(2);

    cout << test.get_last(0) << "\n";
    cout << test.get_last(1) << "\n";

    test.record(3);
    test.record(4);
    test.record(5);
    test.record(6);
    test.record(7);
    test.record(8);
    test.record(9);

    cout << test.get_last(0) << "\n";
    cout << test.get_last(1) << "\n";
    cout << test.get_last(2) << "\n";
    cout << test.get_last(3) << "\n";

    test.record(10);
    test.record(11);
    test.record(12);

    cout << test.get_last(0) << "\n";
    cout << test.get_last(1) << "\n";
    cout << test.get_last(2) << "\n";
    cout << test.get_last(3) << "\n";

    return 0;
}

