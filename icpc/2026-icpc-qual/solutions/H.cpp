// ICPC NERC Kyrgyzstan Qualification 2026 · H · Каждому префиксу по медиане!
// Ограничения: 1 с, 256 МБ
//
// Дана перестановка P длины N. Для каждого префикса P1..Pi найти медиану и вывести её,
// умноженную на 2.
// Медиана набора из k чисел a1 ≤ ... ≤ ak: если k нечётно — a_{(k+1)/2}; если чётно —
// среднее a_{k/2} и a_{k/2+1}. Удвоенная медиана при чётном k — это a_{k/2} + a_{k/2+1}.
//
// Входные данные: в первой строке N (1 ≤ N ≤ 2·10^5); во второй N различных целых чисел
// P1..PN (1 ≤ Pi ≤ N).
// Выходные данные: через пробел N чисел M1..MN, где Mi — удвоенная медиана первых i
// элементов.
//
// Примеры (« / » — переход на новую строку):
//   7 / 5 2 1 4 7 6 3 → 10 7 4 6 8 9 8

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // long of massive
    int l;
    // index of massive
    int n;
    cin >> l;

    vector<int> massive;

    for (int i=0; i<l; i++) {
        cin >> n;
        massive.push_back(n);
    }

    // if (massive.size() % 2 == 0) {

    // } else {

    // }

    for(int i=0; i<massive.size(); i++) {
        cout << massive[0];
    }

}
