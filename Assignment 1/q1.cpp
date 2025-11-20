#include <iostream>
using namespace std;

const int MAXN = 100;

void create(int a[], int &n) {
    cout << "Enter size (<= " << MAXN << "): ";
    cin >> n;
    if (n < 0) n = 0;
    if (n > MAXN) n = MAXN;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void display(int a[], int n) {
    if (n == 0) { cout << "[empty]\n"; return; }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
    cout << '\n';
}

void insertAt(int a[], int &n, int pos, int val) {
    if (n >= MAXN || pos < 0 || pos > n) { cout << "Invalid position.\n"; return; }
    for (int i = n; i > pos; --i) a[i] = a[i - 1];
    a[pos] = val;
    ++n;
}

void deleteAt(int a[], int &n, int pos) {
    if (n == 0 || pos < 0 || pos >= n) { cout << "Invalid position.\n"; return; }
    for (int i = pos; i < n - 1; ++i) a[i] = a[i + 1];
    --n;
}

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; ++i) if (a[i] == key) return i;
    return -1;
}

int main() {
    int a[MAXN], n = 0;
    while (true) {
        cout << "\n---- MENU ----\n"
             << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n"
             << "Choice: ";
        int ch; if (!(cin >> ch)) return 0;

        if (ch == 1) create(a, n);
        else if (ch == 2) display(a, n);
        else if (ch == 3) { int pos, val; cout << "pos value: "; cin >> pos >> val; insertAt(a, n, pos, val); }
        else if (ch == 4) { int pos; cout << "pos to delete: "; cin >> pos; deleteAt(a, n, pos); }
        else if (ch == 5) { int key; cout << "search value: "; cin >> key;
                             int idx = linearSearch(a, n, key);
                             if (idx == -1) cout << "Not found\n"; else cout << "Found at index " << idx << '\n'; }
        else if (ch == 6) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}
