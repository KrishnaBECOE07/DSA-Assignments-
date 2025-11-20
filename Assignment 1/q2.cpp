#include <iostream>
using namespace std;

int main() {
    const int MAXN = 100;
    int a[MAXN], n;
    cout << "Enter n: "; cin >> n;
    if (n > MAXN) n = MAXN;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    // In-place O(n^2): when duplicate found, shift left and shrink n.
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == a[i]) {
                for (int k = j; k < n - 1; ++k) a[k] = a[k + 1];
                --n; --j; // check new element that shifted into j
            }
        }
    }

    cout << "Unique array: ";
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
