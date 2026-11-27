// acmp №32 · Годовой баланс
// https://acmp.ru/index.asp?main=task&id_task=32
// Сложность: 35%
//
// Примеры:
//   18 / 10 → 71
//   1 / -23 → 33

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

long long rearrange(long long value, bool maximize) {
    string digits = to_string(abs(value));
    sort(digits.begin(), digits.end());
    const bool descending = maximize != (value < 0);
    if (descending) {
        reverse(digits.begin(), digits.end());
    } else if (digits.front() == '0' && value != 0) {
        const auto firstNonzero = digits.find_first_not_of('0');
        swap(digits.front(), digits[firstNonzero]);
    }
    const long long magnitude = stoll(digits);
    return value < 0 ? -magnitude : magnitude;
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << rearrange(a, true) - rearrange(b, false) << '\n';
}
