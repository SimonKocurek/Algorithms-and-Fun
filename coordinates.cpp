/*
   A rule looks like this:

   A NE B

   This means this means point A is located northeast of point B.

   A SW C

   means that point A is southwest of C.

   Given a list of rules, check if the sum of the rules validate. For example:

   A N B
   B NE C
   C N A
   does not validate, since A cannot be both north and south of C.

   A NW B
   A N B
   is considered valid.
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> a {
        "A N B",
            "B NE C",
            "C N A"
    };

    vector<string> b {
        "A NW B",
            "A N B"
    };

    vector<string> c {
        "A N B",
            "B N A"
    };

    vector<string> d;
    vector<string> e {
        "A N B",
            "A S B"
    };

    vector<string> f {
        "A N B",
            "B S A",
            "B N C",
            "A N C",
            "C S B",
            "C S A"
    };

    return 0;
}

