// acmp №30 · Часы
// https://acmp.ru/index.asp?main=task&id_task=30
// Сложность: 30%
//
// Примеры:
//   23:59:58 / 23:59:59 → 0 / 0 / 2 / 2 / 0 / 4 / 0 / 0 / 1 / 3

#include <iostream>

using namespace std;

int main() {
    const auto readTime = [] {
        int hours, minutes, seconds;
        char separator;
        cin >> hours >> separator >> minutes >> separator >> seconds;
        return hours * 3600 + minutes * 60 + seconds;
    };

    const int start = readTime();
    const int finish = readTime();
    int counts[10] = {};
    for (int time = start; time <= finish; ++time) {
        const int parts[] = {time / 3600, time / 60 % 60, time % 60};
        for (int part : parts) {
            ++counts[part / 10];
            ++counts[part % 10];
        }
    }

    for (int count : counts) {
        cout << count << '\n';
    }
}
