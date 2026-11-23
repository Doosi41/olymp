// Codeforces Round 1134 (Div. 4) · B · Упрямая ручка
//
// Ручка пишет буквы слева направо, изначально красным. После каждой написанной буквы цвет сам
// переключается (красный ↔ синий). Перед любой буквой (в т.ч. перед первой) можно вручную
// переключить цвет. Нужно написать строку s из символов R/B минимальным числом ручных
// переключений.
//
// Входные данные: t (1 ≤ t ≤ 10^4) наборов. В каждом — n (1 ≤ n ≤ 100), затем строка s длины n
// из символов R и B.
// Выходные данные: для каждого набора — минимальное число ручных переключений.
//
// Пример:
//   5 / 5 / BRRBR / 1 / R / 4 / RBRB / 3 / BBB / 6 / RRBBRB
//   → 2 / 0 / 0 / 3 / 2

#include <iostream>
#include <string>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        string s;
        cin >> n >> s;

        char color = 'R';
        int switches = 0;
        for (char wanted : s) {
            if (color != wanted) {
                ++switches;
                color = color == 'R' ? 'B' : 'R';
            }
            color = color == 'R' ? 'B' : 'R';
        }

        cout << switches << '\n';
    }
}
