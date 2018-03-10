#include <bits/stdc++.h>

using namespace std;

template<class T>
struct node {
    T data;
    node* both;

    node(T data) : data(data) {}
};

template<class T>
class xor_list {
    private:
        node<T>* head;
        node<T>* tail;
        int size;

    public:
        xor_list() : head(nullptr), tail(nullptr), size(0) {}

        void add(node<T>* added) {
            if (head == nullptr) {
                head = added;
                tail = added;

            } else if (head == tail) {
                tail = added;
                tail->both = head;
                head->both = tail;

            } else {
                added->both = tail;
                tail->both = (node<T>*) ((size_t) tail->both ^ (size_t) added);

                tail = added;
            }

            size++;
        }

        node<T>* get(int index) {
            if (index < 0 || index >= size) {
                throw;
            }

            node<T>* previous = nullptr;
            node<T>* current = head;
            for (int i = 0; i < index; ++i) {
                auto temp = current;

                current = (node<T>*) ((size_t) current->both ^ (size_t) previous);
                previous = temp; 
            }

            return current;
        }

        void remove(int index) {
            if (index < 0 || index >= size) {
                throw;
            }

            if (index == 0) {
                auto deleted = head;
                head = head->both;
                head->both = (node<T>*) ((size_t) head->both ^ (size_t) deleted);
                
                delete deleted;

            } else if (index == size - 1) {
                auto deleted = tail;
                tail = tail->both;
                tail->both = (node<T>*) ((size_t) tail->both ^ (size_t) deleted);

                delete deleted;

            } else {
                node<T>* previous = nullptr;
                node<T>* current = head;
                for (int i = 1; i < index; ++i) {
                    auto temp = current;

                    current = (node<T>*) ((size_t) previous ^ (size_t) current->both); 
                    previous = temp;
                }

                node<T>* deleted = (node<T>*) ((size_t) previous ^ (size_t) current->both);
                node<T>* forward = (node<T>*) ((size_t) current ^ (size_t) deleted->both);

                current->both = (node<T>*) ((size_t) current->both ^ (size_t) deleted ^ (size_t) forward);
                forward->both = (node<T>*) ((size_t) forward->both ^ (size_t) deleted ^ (size_t) current);

                delete deleted;
            }

            if (tail == nullptr || head == nullptr) {
                tail = nullptr;
                head = nullptr;
            }

            size--;
        }

};

int main() {
    xor_list<int> test;
    for (int i = 0; i < 10; ++i) {
        auto added = new node<int>(i);
        test.add(added);
    }

    cout << test.get(0)->data << "\n";
    cout << test.get(8)->data << "\n";
    cout << test.get(4)->data << "\n";
    cout << test.get(6)->data << "\n";

    test.remove(0);
    test.remove(0);
    test.remove(1);

    cout << test.get(0)->data << "\n";
    cout << test.get(1)->data << "\n";
    cout << test.get(2)->data << "\n";

    return 0;
}

