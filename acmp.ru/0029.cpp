// acmp №29 · Компьютерная игра
// https://acmp.ru/index.asp?main=task&id_task=29
// Сложность: 38%
//
// Примеры:
//   3 / 1 5 10 → 9
//   3 / 1 5 2 → 3

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> height(n), energy(n);
    for (int& value : height) {
        cin >> value;
    }

    for (int i = 1; i < n; ++i) {
        energy[i] = energy[i - 1] + abs(height[i] - height[i - 1]);
        if (i >= 2) {
            energy[i] = min(energy[i], energy[i - 2] + 3 * abs(height[i] - height[i - 2]));
        }
    }
    cout << energy.back() << '\n';
}
