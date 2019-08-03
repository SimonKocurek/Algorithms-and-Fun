/*
Given an integer k and a string s, find the length of the
longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest
substring with k distinct characters is "bcb".
*/

#include <bits/stdc++.h>

using namespace std;

string longest_substring_with_distinct_chars(string &str, int distinct)
{
    if (distinct == 0) {
        return "";
    }

    string result;
    vector<bool> used(27, false);
    int used_count = 0;
    
    int start = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (!used[str[i] - 'a'])
        {
            used_count++;
            used[str[i] - 'a'] = true;
        }

        while (start <= i && used_count > distinct)
        {
            if (used[str[start] - 'a']) {
                used_count--;
                used[str[start] - 'a'] = false;
            }

            start++;
        }

        if (used_count <= distinct && i - start + 1 > result.length()) {
            result = str.substr(start, i - start + 1);
        }
    }

    return result;
}

int main()
{
    string a = "abcba";
    string b = "";
    string c = "aaaaabbb";
    string d = "abccddeeeef";
    string e = "a";

    cout << longest_substring_with_distinct_chars(a, 2) << "\n";
    cout << longest_substring_with_distinct_chars(b, 2) << "\n";
    cout << longest_substring_with_distinct_chars(c, 1) << "\n";
    cout << longest_substring_with_distinct_chars(d, 3) << "\n";
    cout << longest_substring_with_distinct_chars(e, 1) << "\n";

    return 0;
}
