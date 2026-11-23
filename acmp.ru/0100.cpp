// acmp №100 · Счастливые билеты
// https://acmp.ru/index.asp?main=task&id_task=100
// Сложность: 68%
//
// Требуется вычислить количество N-значных счастливых билетов. Напомним, что билет
// называется счастливым, если сумма первой половины его цифр равна сумме другой его
// половины. Например, билет 064109 счастливый, т.к. 0+6+4=1+0+9.
//
// Входные данные: в единственной строке входного файла INPUT.TXT записано натуральное
// четное число N (N ≤ 100) – количество цифр в билете.
//
// Выходные данные: в единственную строку выходного файла OUTPUT.TXT нужно вывести одно
// целое число – количество N-значных счастливых билетов.
//
// Примеры:
//   4 → 670
//   6 → 55252
//   12 → 39581170420

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string add(const string& a, const string& b) {
    string result;
    int carry = 0;

    for (int i = static_cast<int>(a.size()) - 1, j = static_cast<int>(b.size()) - 1;
         i >= 0 || j >= 0 || carry; --i, --j) {
        int sum = carry;
        if (i >= 0) sum += a[i] - '0';
        if (j >= 0) sum += b[j] - '0';
        result.push_back('0' + sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string multiply(const string& a, const string& b) {
    vector<int> digits(a.size() + b.size());
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        for (int j = static_cast<int>(b.size()) - 1; j >= 0; --j) {
            digits[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = digits.size() - 1; i > 0; --i) {
        digits[i - 1] += digits[i] / 10;
        digits[i] %= 10;
    }

    string result;
    size_t first = 0;
    while (first + 1 < digits.size() && digits[first] == 0) ++first;
    for (; first < digits.size(); ++first) result.push_back('0' + digits[first]);
    return result;
}

int main() {
    int n;
    cin >> n;

    int h = n / 2;
    int max_sum = 9 * h;

    // ways[s] — число половинок билета с суммой цифр s.
    vector<string> ways(max_sum + 1, "0");
    ways[0] = "1";

    for (int digits = 0; digits < h; ++digits) {
        vector<string> next(max_sum + 1, "0");

        for (int sum = 0; sum <= max_sum; ++sum) {
            for (int digit = 0; digit <= 9 && sum + digit <= max_sum; ++digit) {
                if (ways[sum] != "0") {
                    next[sum + digit] = add(next[sum + digit], ways[sum]);
                }
            }
        }

        ways = next;
    }

    string lucky = "0";
    for (const string& count : ways) {
        lucky = add(lucky, multiply(count, count));
    }

    cout << lucky << '\n';
}
