#include <bits/stdc++.h>

using namespace std;

void TestGroupsOf(int group_size, char& test_paper, vector<bool>& bottles) {
    int remaining = group_size;    
    for (int i = 0; i < bottles.size(); ++i) {
        if (remaining > 0) {
            test_paper = test_paper || bottles[i];
        }

        if (--remaining == -group_size) {
            remaining = group_size;
        }
    }
}

void ExecuteTests(vector<bool>& bottles, vector<char>& test_papers) {
    int jump = 1;
    for (auto& test_paper : test_papers) {
        TestGroupsOf(jump, test_paper, bottles);
        jump *= 2;
    }
}

int ExtractResult(vector<char>& test_papers) {
    int result = 0;

    int bit = 1;
    for (auto& test_paper : test_papers) {
        if (!test_paper) {
            result += bit;
        }

        bit *= 2;
    }    

    return result;
}

int Tested(vector<bool>& bottles, int tests) {
    vector<char> test_papers(tests, false);
    ExecuteTests(bottles, test_papers);
    return ExtractResult(test_papers);
}

int main() {
    vector<bool> bottles(1000, false);

    for (int i = 0; i < 10; ++i) {
        bottles[i] = true;

        cout << "True: " << i << "\n";
        cout << "Got: " << Tested(bottles, 10) << "\n";
        cout << "\n";

        bottles[i] = false;
    }

    for (int i = 0; i < 10; ++i) {
        int poissoned = rand() % (1000 + 1);
        bottles[poissoned] = true;

        cout << "True: " << poissoned << "\n";
        cout << "Got: " << Tested(bottles, 10) << "\n";
        cout << "\n";

        bottles[poissoned] = false;
    }

    return 0;
}
