// acmp №24 · Вырубка деревьев
// https://acmp.ru/index.asp?main=task&id_task=24
// Сложность: 46%
//
// Примеры:
//   5 3 → 4

#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m <= 1) {
        cout << (m == 0 ? 1 : n) << '\n';
        return 0;
    }

    int ways = 0;
    for (int span = m - 1; span < n; span += m - 1) {
        ways += n - span;
    }
    cout << ways << '\n';
}
