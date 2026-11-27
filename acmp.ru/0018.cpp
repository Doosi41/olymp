// acmp №18 · Факториал
// https://acmp.ru/index.asp?main=task&id_task=18
// Сложность: 42%

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> digits{1};
    for (int factor = 2; factor <= n; ++factor) {
        int carry = 0;
        for (int& digit : digits) {
            const int product = digit * factor + carry;
            digit = product % 10;
            carry = product / 10;
        }
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (auto digit = digits.rbegin(); digit != digits.rend(); ++digit) {
        cout << *digit;
    }
    cout << '\n';
}
