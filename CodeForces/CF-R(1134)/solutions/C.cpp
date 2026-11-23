// Codeforces Round 1134 (Div. 4) · C · Books on a Shelf
// https://codeforces.com/contest/2290/problem/C

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;

        map<long long, int> frequency;
        for (int i = 0; i < n; ++i) {
            long long height;
            cin >> height;
            ++frequency[height];
        }

        vector<long long> left, middle, right;
        int visible = 0;
        for (const auto& [height, count] : frequency) {
            left.push_back(height);
            visible += min(count, 2);
            for (int copies = 0; copies < count - 2; ++copies) {
                middle.push_back(height);
            }
            if (count >= 2) {
                right.push_back(height);
            }
        }

        cout << visible << '\n';
        for (long long height : left) cout << height << ' ';
        for (long long height : middle) cout << height << ' ';
        for (auto it = right.rbegin(); it != right.rend(); ++it) cout << *it << ' ';
        cout << '\n';
    }
}
