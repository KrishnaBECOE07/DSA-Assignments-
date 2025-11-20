#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 2000;

struct CharStack {
    char a[MAX]; int top;
    CharStack(): top(-1) {}
    bool empty(){ return top==-1; }
    void push(char c){ if(top<MAX-1) a[++top]=c; }
    char pop(){ return empty()? '\0' : a[top--]; }
    char peek(){ return empty()? '\0' : a[top]; }
};

int prec(char op){
    if (op=='^') return 3;
    if (op=='*' || op=='/') return 2;
    if (op=='+' || op=='-') return 1;
    return 0;
}
bool isRightAssoc(char op){ return op=='^'; }

int main() {
    char in[MAX];
    cout << "Enter infix: ";
    cin.getline(in, MAX);
    if (in[0]=='\0') cin.getline(in, MAX);

    CharStack st;
    cout << "Postfix: ";

    for (int i = 0; in[i]; ++i) {
        char c = in[i];
        if (c==' ') continue;

        if (c>='0' && c<='9') {            // read full number
            while (in[i]>='0' && in[i]<='9') { cout << in[i]; ++i; }
            cout << ' ';
            --i;                            // step back one
        }
        else if ((c>='A'&&c<='Z') || (c>='a'&&c<='z')) { // variable
            cout << c << ' ';
        }
        else if (c=='(') st.push(c);
        else if (c==')') {
            while (!st.empty() && st.peek()!='(') { cout << st.pop() << ' '; }
            if (!st.empty()) st.pop();      // pop '('
        }
        else { // operator
            while (!st.empty() && st.peek()!='(' &&
                   (prec(st.peek()) > prec(c) ||
                   (prec(st.peek())==prec(c) && !isRightAssoc(c))))
                cout << st.pop() << ' ';
            st.push(c);
        }
    }
    while (!st.empty()) cout << st.pop() << ' ';
    cout << '\n';
    return 0;
}
