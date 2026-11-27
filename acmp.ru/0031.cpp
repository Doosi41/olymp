// acmp №31 · Неподвижные точки
// https://acmp.ru/index.asp?main=task&id_task=31
// Сложность: 47%
//
// Примеры:
//   5 2 → 20
//   9 6 → 168
//   2 1 → 0
//   9 0 → 133496

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int choices = 1;
    for (int i = 1; i <= k; ++i) {
        choices = choices * (n - i + 1) / i;
    }

    // All positions outside the chosen fixed points must form a derangement.
    int derangements[10] = {1, 0};
    for (int size = 2; size <= n - k; ++size) {
        derangements[size] = (size - 1) * (derangements[size - 1] + derangements[size - 2]);
    }
    cout << choices * derangements[n - k] << '\n';
}
