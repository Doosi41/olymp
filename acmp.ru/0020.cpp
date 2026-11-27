// acmp №20 · Пилообразная последовательность
// https://acmp.ru/index.asp?main=task&id_task=20
// Сложность: 38%
//
// Примеры:
//   3 / 1 2 3 → 2
//   12 / 5 7 6 3 4 2 7 1 8 9 4 5 → 7

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, previous;
    cin >> n >> previous;
    int best = 1;
    int length = 1;
    int previousDirection = 0;
    for (int i = 1; i < n; ++i) {
        int value;
        cin >> value;
        const int direction = (value > previous) - (value < previous);
        if (direction == 0) {
            length = 1;
        } else if (direction == -previousDirection) {
            ++length;
        } else {
            length = 2;
        }
        best = max(best, length);
        previous = value;
        previousDirection = direction;
    }
    cout << best << '\n';
}
