#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int r, c, A[MAX][MAX];
    cout << "Enter rows cols: "; cin >> r >> c;
    if (r > MAX) r = MAX; if (c > MAX) c = MAX;

    cout << "Enter matrix (" << r << "x" << c << "):\n";
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) cin >> A[i][j];

    int rowSum[MAX] = {0}, colSum[MAX] = {0};

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
        }

    cout << "Row sums:\n";
    for (int i = 0; i < r; ++i) cout << "Row " << i << ": " << rowSum[i] << '\n';

    cout << "Column sums:\n";
    for (int j = 0; j < c; ++j) cout << "Col " << j << ": " << colSum[j] << '\n';

    return 0;
}
