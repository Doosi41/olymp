// Codeforces Round 1134 (Div. 4) · F · Value Counters
// https://codeforces.com/contest/2290/problem/F

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;
        vector<int> permutation(n + 1);
        bool possible = true;

        for (int value = 1; value <= n; ++value) {
            int counter;
            cin >> counter;
            const int position = counter + n - value + 1;
            if (position < 1 || position > n || permutation[position] != 0) {
                possible = false;
            } else {
                permutation[position] = value;
            }
        }

        if (!possible) {
            cout << "-1\n";
            continue;
        }
        for (int position = 1; position <= n; ++position) {
            cout << permutation[position] << ' ';
        }
        cout << '\n';
    }
}
