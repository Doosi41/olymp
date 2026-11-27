// acmp №17 · Поле чудес
// https://acmp.ru/index.asp?main=task&id_task=17
// Сложность: 31%
//
// Примеры:
//   13 / 5 3 1 3 5 2 5 3 1 3 5 2 5 → 6
//   4 / 1 1 1 1 → 1
//   4 / 1 2 3 1 → 3

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sectors(n - 1);
    for (int& value : sectors) {
        cin >> value;
    }

    // The final reading repeats the starting sector after whole revolutions.
    vector<int> prefix(sectors.size());
    for (int i = 1; i < n - 1; ++i) {
        int matched = prefix[i - 1];
        while (matched > 0 && sectors[i] != sectors[matched]) {
            matched = prefix[matched - 1];
        }
        prefix[i] = matched + (sectors[i] == sectors[matched]);
    }

    const int length = n - 1;
    const int period = length - prefix.back();
    cout << (length % period == 0 ? period : length) << '\n';
}
