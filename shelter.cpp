#include <bits/stdc++.h>

using namespace std;

enum class animal {DOG, CAT};

struct inserted_animal {
    animal inserted;
    uint64_t age;

    inserted_animal(animal inserted, uint64_t age) : inserted(inserted), age(age) {}
};

// Structure for returning oldest animals.. may use list
class shelter {
    private:
        uint64_t age = 0;
        list<inserted_animal> cats;
        list<inserted_animal> dogs;

    public:
        void enqueue(animal a) {
            inserted_animal inserted(a, age++);
            switch (a) {
                case animal::DOG: dogs.push_back(inserted); break;
                case animal::CAT: cats.push_back(inserted); break;
            }
        }

        animal dequeue_any() {
            if (cats.empty() && dogs.empty()) {
                throw;
            }

            if (cats.empty() || dogs.front().age < cats.front().age) {
                return dequeue_dog();
            } else {
                return dequeue_cat();
            }
        }

        animal dequeue_dog() {
            return dequeue_animal(dogs);
        }

        animal dequeue_cat() {
            return dequeue_animal(cats);
        }

        animal dequeue_animal(list<inserted_animal> &queue) {
            if (queue.empty()) {
                throw;
            }

            auto data = queue.front();
            queue.pop_front();
            return data.inserted;
        }
};

void print(animal a) {
    switch (a) {
        case animal::DOG:
            cout << "Dog\n";
            break;
        case animal::CAT:
            cout << "Cat\n";
            break;
    }
}

int main() {
    shelter test;
    test.enqueue(animal::DOG);
    test.enqueue(animal::DOG);
    test.enqueue(animal::CAT);
    test.enqueue(animal::CAT);
    test.enqueue(animal::CAT);
    test.enqueue(animal::DOG);

    print(test.dequeue_dog());
    print(test.dequeue_any());
    print(test.dequeue_any());
    print(test.dequeue_any());
    print(test.dequeue_cat());
    print(test.dequeue_any());
    
    return 0;
}

