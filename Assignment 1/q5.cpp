#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int r1, c1, r2, c2;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};

    cout << "Enter r1 c1: "; cin >> r1 >> c1;
    cout << "Enter r2 c2: "; cin >> r2 >> c2;

    if (r1 > MAX) r1 = MAX; if (c1 > MAX) c1 = MAX;
    if (r2 > MAX) r2 = MAX; if (c2 > MAX) c2 = MAX;

    if (c1 != r2) { cout << "Invalid dimensions for multiplication\n"; return 0; }

    cout << "Enter A (" << r1 << "x" << c1 << "):\n";
    for (int i = 0; i < r1; ++i) for (int j = 0; j < c1; ++j) cin >> A[i][j];

    cout << "Enter B (" << r2 << "x" << c2 << "):\n";
    for (int i = 0; i < r2; ++i) for (int j = 0; j < c2; ++j) cin >> B[i][j];

    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j) {
            int sum = 0;
            for (int k = 0; k < c1; ++k) sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }

    cout << "C = A x B:\n";
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) cout << C[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
