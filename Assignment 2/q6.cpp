#include <iostream>
using namespace std;

struct Triplet { int r, c, v; };

int main() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int mat[10][10];
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) cin >> mat[i][j];

    Triplet t[100];
    int k = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (mat[i][j] != 0)
                t[k++] = {i, j, mat[i][j]};

    cout << "Triplet form (r c v):\n";
    for (int i = 0; i < k; ++i)
        cout << t[i].r << " " << t[i].c << " " << t[i].v << endl;
}
