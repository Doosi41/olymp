// Codeforces Round 1134 (Div. 4) · D · Letters Down
// https://codeforces.com/contest/2290/problem/D

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        string s;
        cin >> n >> s;

        bool use[26]{};
        for (int i = 0; i < n / 2; ++i) {
            const int low = min(s[i], s[n - 1 - i]) - 'a';
            const int high = max(s[i], s[n - 1 - i]) - 'a';
            for (int letter = low + 1; letter <= high; ++letter) {
                use[letter] = true;
            }
        }

        int operations = 0;
        for (bool needed : use) operations += needed;
        cout << operations << '\n';
    }
}
