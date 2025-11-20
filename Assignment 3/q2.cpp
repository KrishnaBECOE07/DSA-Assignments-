#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

struct CharStack {
    char a[MAX];
    int top;
    CharStack() : top(-1) {}
    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }
    void push(char c){ if(!isFull()) a[++top]=c; }
    char pop()      { return isEmpty() ? '\0' : a[top--]; }
};

int main() {
    char s[MAX];
    cout << "Enter string (no spaces or use_underscores): ";
    cin >> s;

    CharStack st;
    for (int i = 0; s[i]; ++i) st.push(s[i]);

    cout << "Reversed: ";
    while (!st.isEmpty()) cout << st.pop();
    cout << '\n';
    return 0;
}
