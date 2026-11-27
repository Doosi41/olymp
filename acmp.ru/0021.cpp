// acmp №21 · Зарплата
// https://acmp.ru/index.asp?main=task&id_task=21
// Сложность: 4%
//
// Примеры:
//   100 500 1000 → 900
//   36 11 20 → 25

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max({a, b, c}) - min({a, b, c}) << '\n';
}
