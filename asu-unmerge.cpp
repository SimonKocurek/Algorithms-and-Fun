#include <bits/stdc++.h>

using namespace std;

void unmerge(vector<int>& result, vector<int>& helper, vector<string>& tokens, int start, int mid, int end) {
    auto token = tokens.back();
    tokens.pop_back();

    int cursor = 0;
    int i = start;
    int j = mid;

    while (i < mid && j < end) {
        if (token[cursor] == '+') {
            helper[i] = result[start + cursor];
            i++;

        } else {
            helper[j] = result[start + cursor];
            j++;
        }

        cursor++;
    }

    while (i < mid) {
        helper[i++] = result[start + cursor];
        cursor++;
    }
    while (j < end) {
        helper[j++] = result[start + cursor];
        cursor++;
    }

    for (int i = start; i < end; ++i) {
        result[i] = helper[i];
    }
}

void unsort(vector<int>& result, vector<int>& helper, vector<string>& tokens, int start, int end) {
    if (start + 1 >= end) {
        return;
    }

    int mid = (start + end) / 2;
    unmerge(result, helper, tokens, start, mid, end);
    unsort(result, helper, tokens, mid, end);
    unsort(result, helper, tokens, start, mid);
}

void add_token(vector<string>& tokens, string& debug, int start, int mid, int end) {
    int plusses = mid - start;
    int minuses = end - mid;

    int i = 0;
    while (plusses > 0 && minuses > 0) {
        if (debug[i] == '+') {
            plusses--;
        } else {
            minuses--;
        }

        i++;
    }

    auto added = debug.substr(0, i);
    tokens.push_back(added);
    debug.erase(0, i);
}

void tokenize(vector<string>& tokens, string& debug, int start, int end) {
    if (start + 1 >= end) {
        return;
    }

    int mid = (start + end) / 2;
    tokenize(tokens, debug, start, mid);
    tokenize(tokens, debug, mid, end);

    add_token(tokens, debug, start, mid, end);
}

int main() {
    int size;
    cin >> size;

    vector<int> result(size);
    vector<int> helper(size);
    for (int i = 1; i <= size; ++i) {
        result[i - 1] = i;
    }

    string debug;
    cin >> debug;
    vector<string> tokens;
    tokenize(tokens, debug, 0, size);

    unsort(result, helper, tokens, 0, size);
    for (auto value : result) {
        cout << value << " ";
    }

    return 0;
}
