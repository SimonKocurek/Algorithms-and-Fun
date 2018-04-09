#include <bits/stdc++.h>

using namespace std;

class Tree {
  private:
    unique_ptr<Tree> left;
    unique_ptr<Tree> right;

  public:
    int value;

    Tree(int value) : left(nullptr), right(nullptr), value(value) {}

    void Insert(int inserted) {
      if (inserted < value) {
        if (left != nullptr) {
          left->Insert(inserted);
        } else {
          left = make_unique<Tree>(inserted);
        }
      }

      if (inserted > value) {
        if (right != nullptr) {
          right->Insert(inserted);
        } else {
          right = make_unique<Tree>(inserted);
        }
      }
    }

    Tree* Find(int searched) {
      if (searched == value) {
        return this;
      }

      if (searched < value && left != nullptr) {
        return left->Find(searched);
      } 
      if (searched > value && right != nullptr){
        return right->Find(searched);
      }

      return nullptr;
    }

    void Delete(int deleted) {
      if (deleted < value && left != nullptr) {
        if (left->value == deleted) {
          left = nullptr;
        } else {
          left->Delete(deleted);
        }

      }

      if (deleted > value && right != nullptr) {
        if (right->value == deleted) {
          right = nullptr;
        } else {
          right->Delete(deleted);
        }
      }
    }

    void GetRandomNode(Tree*& selected, int& chance) {
      if (rand() % chance == 0) {
        selected = this;
      }

      if (left != nullptr) {
        left->GetRandomNode(selected, ++chance);
      }

      if (right != nullptr) {
        right->GetRandomNode(selected, ++chance);
      }
    }

    Tree* GetRandomNode() {
      Tree* result = this;
      int chance = 1;

      GetRandomNode(result, chance);
      return result;
    }

};

int main() {
  auto root = make_unique<Tree>(1);
  root->Insert(0);
  root->Insert(2);
  root->Insert(-2);
  root->Insert(0);
  root->Insert(-3);
  root->Insert(4);
  root->Insert(3); 

  root->Delete(-2);

  cout << root->Find(1) << "\n";
  cout << root->Find(2) << "\n";
  cout << root->Find(-2) << "\n";
  cout << root->Find(-3) << "\n";
  cout << root->Find(33) << "\n";
  cout << root->Find(4) << "\n";
  cout << root->Find(3) << "\n";
  cout << root->Find(0) << "\n";

  root->Insert(6);
  root->Insert(-3);


  vector<int> results (10, 0);
  for (int i = 0; i < 1000000; ++i) {
    results[root->GetRandomNode()->value + 3]++;
  }

  for (int i = 0; i < results.size(); ++i) {
    cout << (i - 3) << ": " << results[i] << "\n";
  }

  return 0;
}

