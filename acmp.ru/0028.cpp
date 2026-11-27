// acmp №28 · Симметрия
// https://acmp.ru/index.asp?main=task&id_task=28
// Сложность: 19%
//
// Примеры:
//   0 0 0 1 / 10 10 → -10 10
//   0 0 1 0 / 10 10 → 10 -10

#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if (x1 == x2) {
        x = 2 * x1 - x;
    } else {
        y = 2 * y1 - y;
    }
    cout << x << ' ' << y << '\n';
}
