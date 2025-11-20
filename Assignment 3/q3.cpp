#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

struct StackC {
    char a[MAX]; int top;
    StackC(): top(-1) {}
    bool empty(){ return top==-1; }
    void push(char c){ if(top<MAX-1) a[++top]=c; }
    char pop(){ return empty()? '\0' : a[top--]; }
    char peek(){ return empty()? '\0' : a[top]; }
};

bool isPair(char open, char close){
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

int main() {
    char s[MAX];
    cout << "Enter expression: ";
    cin.getline(s, MAX);          // in case previous newline remains
    if (s[0]=='\0') cin.getline(s, MAX);

    StackC st;
    for (int i = 0; s[i]; ++i) {
        char c = s[i];
        if (c=='('||c=='{'||c=='[') st.push(c);
        else if (c==')'||c=='}'||c==']') {
            if (st.empty() || !isPair(st.pop(), c)) { cout << "Not Balanced\n"; return 0; }
        }
    }
    cout << (st.empty() ? "Balanced" : "Not Balanced") << '\n';
    return 0;
}
