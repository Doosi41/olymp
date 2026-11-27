// acmp №27 · Художник
// https://acmp.ru/index.asp?main=task&id_task=27
// Сложность: 26%
//
// Примеры:
//   5 5 / 2 / 1 1 3 3 / 2 2 4 4 → 18

#include <iostream>

using namespace std;

int main() {
    int width, height, n;
    cin >> width >> height >> n;
    int coverage[101][101] = {};
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++coverage[y1][x1];
        --coverage[y1][x2];
        --coverage[y2][x1];
        ++coverage[y2][x2];
    }

    int unpainted = 0;
    for (int y = 0; y < height; ++y) {
        int rowSum = 0;
        for (int x = 0; x < width; ++x) {
            rowSum += coverage[y][x];
            coverage[y][x] = rowSum;
            if (y > 0) {
                coverage[y][x] += coverage[y - 1][x];
            }
            unpainted += (coverage[y][x] == 0);
        }
    }
    cout << unpainted << '\n';
}
