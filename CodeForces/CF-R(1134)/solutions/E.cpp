// Codeforces Round 1134 (Div. 4) · E · Avalanche
// https://codeforces.com/contest/2290/problem/E

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n, k;
        cin >> n >> k;
        vector<long long> stones(n);
        for (long long& value : stones) cin >> value;

        // ways[i] is the parity of all moves caused by one initial stone in pile i.
        vector<int> ways(n);
        int window_sum = 0;
        for (int i = 0; i < n; ++i) {
            ways[i] = 1 ^ window_sum;
            window_sum ^= ways[i];
            if (i >= k) window_sum ^= ways[i - k];
        }

        int moves_parity = 0;
        for (int i = 0; i < n; ++i) {
            if (stones[i] & 1LL) moves_parity ^= ways[i];
        }
        cout << (moves_parity ? "Alice\n" : "Bob\n");
    }
}
