#include <iostream>
#include <vector>

using namespace std;


int main () {
    long long n, k;
    cin >> n >> k;

    vector<int> a;
    
    for (int i = 0; i < n; i++) {
        // Добавляем элемент в массив
        a.push_back(i);
        int j = i;

        // Сортируем массив с помощью вставки
        while ((j > 1) && (a[j] < a[j - 1])) {
            swap(a[j], a[j - 1]);
            j--;
        }
    }

    // Выводим результат
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    
}