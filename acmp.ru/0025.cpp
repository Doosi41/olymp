// acmp №25 · Больше-меньше
// https://acmp.ru/index.asp?main=task&id_task=25
// Сложность: 3%
//
// Примеры:
//   5 / 7 → <
//   -7 / -12 → >
//   13 / 13 → =

#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    const char comparison = a < b ? '<' : (a > b ? '>' : '=');
    cout << comparison << '\n';
}
