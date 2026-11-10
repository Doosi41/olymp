// Codeforces Round 1132 (Div. 2) · B
//
// Условие: <вставь текст условия сюда — с сайта я его получить не смог (403)>
//
// Ограничения: ?
//
// Входные данные: ?
// Выходные данные: ?
//
// Пример: ?
//
// Статус: черновик (решение не закончено / не проверено)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        if (k < n && a[n - k - 1] == a[n - k]) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (int i = n - 1; i >= n - k; i--) {
            cout << a[i] << " ";
        }

        for (int i = n - k - 1; i >= 0; i--) {
            cout << a[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}
