#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char s[10][100];
    for (int i = 0; i < n; ++i) cin >> s[i];

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (strcmp(s[i], s[j]) > 0) {
                char t[100];
                strcpy(t, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], t);
            }

    cout << "Sorted strings:\n";
    for (int i = 0; i < n; ++i) cout << s[i] << endl;
}
