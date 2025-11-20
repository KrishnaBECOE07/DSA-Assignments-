#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
    char s[100], out[100];
    cout << "Enter string: ";
    cin >> s;
    int j = 0;
    for (int i = 0; s[i]; ++i)
        if (!isVowel(s[i])) out[j++] = s[i];
    out[j] = '\0';
    cout << "Without vowels: " << out << endl;
}
