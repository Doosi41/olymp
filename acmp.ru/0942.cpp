// acmp №942 · Олимпиада
// https://acmp.ru/index.asp?main=task&id_task=942
// Сложность: 2%
//
// Трое студентов — пятикурсник, третьекурсник и первокурсник — решают задачи олимпиады по
// правилам ACM. Пятикурсник решает задачи строго по порядку (с первой до последней),
// третьекурсник — строго в обратном порядке (с последней до первой), первокурсник — от самой
// простой к самой сложной (сложность = время решения). Одну и ту же задачу все решают за
// одинаковое время. Неправильных попыток нет, штраф за задачу — число минут от начала
// соревнования до её посылки. Побеждает тот, кто за 300 минут решил больше задач, а при
// равенстве — набравший меньше штрафа. Если и штраф равен, побеждает студент с младшего курса.
// Определить, кто победит.
//
// Входные данные: в первой строке INPUT.TXT — число N (N ≤ 10), количество задач; во второй
// через пробел N натуральных чисел — время решения каждой задачи в минутах (не больше 300).
//
// Выходные данные: в OUTPUT.TXT — номер курса победителя.
//
// Примеры:
//   3 / 40 30 60 → 1
//   4 / 10 20 30 40 → 1

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto result = [](const vector<int>& order) {
        int time = 0, solved = 0, penalty = 0;
        for (int task : order) {
            if (time + task > 300) break;
            time += task;
            ++solved;
            penalty += time;
        }
        return pair<int, int>{solved, penalty};
    };

    vector<int> five_order = a;
    vector<int> three_order = a;
    reverse(three_order.begin(), three_order.end());
    vector<int> one_order = a;
    sort(one_order.begin(), one_order.end());

    const auto five = result(five_order);
    const auto three = result(three_order);
    const auto one = result(one_order);
    const vector<pair<int, pair<int, int>>> students = {{5, five}, {3, three}, {1, one}};

    int winner = 5;
    pair<int, int> best = five;
    for (const auto& student : students) {
        const int course = student.first;
        const auto& current = student.second;
        if (current.first > best.first ||
            (current.first == best.first && (current.second < best.second ||
             (current.second == best.second && course < winner)))) {
            winner = course;
            best = current;
        }
    }

    cout << winner << '\n';

}
