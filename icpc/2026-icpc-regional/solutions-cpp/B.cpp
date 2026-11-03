// B · Пицца после контеста — C++ по идее разбора Slamur (../solutions-py/B.py)
// Площади кусков относятся как 3 : 4 (37,5π у пиццы 30 см и 50π у пиццы 40 см), а каждому
// нужен хотя бы один кусок, поэтому есть всего два варианта: у всех по малому куску или у всех
// по большому. Людей t = 3N. Считаем пиццы каждого варианта и берём меньшее число;
// при ничьей выигрывает вариант с меньшим остатком по площади.

#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long t = 3 * n;

    long long small = (t + 5) / 6;   // ceil(t / 6)
    long long large = (t + 7) / 8;   // ceil(t / 8)

    long long left_small = (small * 6 - t) * 3;   // остаток в единицах площади: малый кусок = 3
    long long left_large = (large * 8 - t) * 4;   // большой кусок = 4

    if (small < large || (small == large && left_small <= left_large)) {
        cout << small << " " << 0 << "\n";
    } else {
        cout << 0 << " " << large << "\n";
    }
}
