// acmp №19 · Ферзь, ладья и конь
// https://acmp.ru/index.asp?main=task&id_task=19
// Сложность: 29%
//
// На шахматной доске 8х8 расположены три фигуры: ферзь, ладья и конь. Требуется определить
// количество пустых полей доски, которые находятся под боем. Фигуры могут «бить» через другие
// фигуры (например, ферзь бьёт D5 через ладью).
//
// Входные данные: в единственной строке INPUT.TXT через пробел координаты ферзя, ладьи и
// коня соответственно. Координата — английская буква от A до H и цифра от 1 до 8.
//
// Выходные данные: в OUTPUT.TXT — количество пустых полей, которые бьют указанные фигуры.
//
// Пример:
//   D1 D3 E5 → 29

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    string queen, rook, knight;
    cin >> queen >> rook >> knight;

    auto column = [](const string& square) { return square[0] - 'A'; };
    auto row = [](const string& square) { return square[1] - '1'; };

    const int qx = column(queen), qy = row(queen);
    const int rx = column(rook), ry = row(rook);
    const int kx = column(knight), ky = row(knight);
    int attacked = 0;

    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if ((x == qx && y == qy) || (x == rx && y == ry) || (x == kx && y == ky)) {
                continue;
            }

            const bool queen_attacks = x == qx || y == qy || abs(x - qx) == abs(y - qy);
            const bool rook_attacks = x == rx || y == ry;
            const int dx = abs(x - kx), dy = abs(y - ky);
            const bool knight_attacks = dx * dy == 2;
            attacked += queen_attacks || rook_attacks || knight_attacks;
        }
    }

    cout << attacked << '\n';

}
