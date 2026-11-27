// acmp №22 · Единицы
// https://acmp.ru/index.asp?main=task&id_task=22
// Сложность: 16%
//
// Примеры:
//   5 → 2
//   7 → 3

#include <iostream>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    int ones = 0;
    while (n != 0) {
        n &= n - 1;
        ++ones;
    }
    cout << ones << '\n';
}
