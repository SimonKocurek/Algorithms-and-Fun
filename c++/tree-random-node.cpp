#include <bits/stdc++.h>

using namespace std;

class Tree {
  private:
    unique_ptr<Tree> left;
    unique_ptr<Tree> right;

  public:
    int size;
    int value;

    Tree(int value) : left(nullptr), right(nullptr), size(1), value(value) {}

    int Insert(int inserted) {
      auto added = 0;

      if (inserted < value) {
        if (left) {
          added += left->Insert(inserted);
        } else {
          left = make_unique<Tree>(inserted);
          added++;
        }
      }

      if (inserted > value) {
        if (right) {
          added += right->Insert(inserted);
        } else {
          right = make_unique<Tree>(inserted);
          added++;
        }
      }

      size += added;
      return added;
    }

    Tree* Find(int searched) {
      if (searched == value) {
        return this;
      }

      if (searched < value && left) {
        return left->Find(searched);
      } 
      if (searched > value && right){
        return right->Find(searched);
      }

      return nullptr;
    }

    int Delete(int deleted) {
      auto deleted_count = 0;

      if (deleted < value && left) {
        if (left->value == deleted) {
          deleted_count = left->size;
          left = nullptr;
        } else {
          deleted_count = left->Delete(deleted);
        }
      }

      if (deleted > value && right) {
        if (right->value == deleted) {
          deleted_count = right->size;
          right = nullptr;
        } else {
          deleted_count = right->Delete(deleted);
        }
      }

      size -= deleted_count;
      return deleted_count;
    }

    Tree* GetRandomNode(const int chosen) {
      if (chosen == 0) {
        return this;
      }

      auto left_size = left ? left->size : 0;
      if (chosen <= left_size) {
        return left->GetRandomNode(chosen - 1);
      } else {
        return right->GetRandomNode(chosen - 1 - left_size);
      }
    }

    Tree* GetRandomNode() {
      int chosen = random() % size;
      return GetRandomNode(chosen);
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

