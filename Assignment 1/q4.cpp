#include <iostream>
using namespace std;

int main() {
    const int MAXN = 100;
    int a[MAXN], n;
    cout << "Enter n: "; cin >> n;
    if (n > MAXN) n = MAXN;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = n - 1;
    while (l < r) { int t = a[l]; a[l] = a[r]; a[r] = t; ++l; --r; }

    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
