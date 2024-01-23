#include <iostream>
using namespace std;

int calculateCombinations(int x, int y, int z, int w) {
    int combinations = 0;

    for (int ix = 0; ix <= w / x; ++ix) {
        for (int iy = 0; iy <= w / y; ++iy) {
            int currentWeight = ix * x + iy * y;
            int remainingWeight = w - currentWeight;

            if (remainingWeight >= 0 && remainingWeight % z == 0) {
                // Instead of using the '+ 1' approach, directly increment the 'combinations' variable
                combinations += remainingWeight / z;
            }
        }
    }
    /*
    2 2 2
    0 -> 0 <= 1 -> 0
      0 -> 0 <= 1 -> 0
    1 + 1 = 2
    2 - 2 = 0

    */

    return combinations;
}

int main() {

    setlocale(0, "");

    int X, Y, Z, W;

    while (true) {
        cout << "Введите вес ириски (X): ";
        cin >> X;

        cout << "Введите вес мандарина (Y): ";
        cin >> Y;

        cout << "Введите вес пряника (Z): ";
        cin >> Z;

        cout << "Введите желаемый общий вес (W): ";
        cin >> W;
        if ((X < 1 || Y < 1 || Z < 1) || (X >= 100 || Y >= 100 || Z >= 100) || (W >= 1000)) {
            cout << "Ошибка!" << endl;
            break;
        }
        else {
            int result = calculateCombinations(X, Y, Z, W);
            cout << "Количество вариантов: " << result << endl;
            break;
        }

    }

    return 0;
}