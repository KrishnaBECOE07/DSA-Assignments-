#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s1[100], s2[100];
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    strcat(s1, s2);
    cout << "Concatenated: " << s1 << endl;
}
