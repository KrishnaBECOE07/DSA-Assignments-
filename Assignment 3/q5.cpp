#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000;

struct IntStack {
    long long a[MAX]; int top;
    IntStack(): top(-1) {}
    bool empty(){ return top==-1; }
    void push(long long x){ if(top<MAX-1) a[++top]=x; }
    long long pop(){ return empty()? 0 : a[top--]; }
};

int main() {
    char line[2000];
    cout << "Enter postfix (space-separated): ";
    cin.getline(line, 2000);
    if (line[0]=='\0') cin.getline(line, 2000);

    IntStack st;
    for (int i = 0; line[i]; ) {
        if (line[i]==' ') { ++i; continue; }

        // number (possibly negative if prefixed with '-')
        if ((line[i]>='0' && line[i]<='9') || 
            (line[i]=='-' && line[i+1]>='0' && line[i+1]<='9')) {
            long long sign = 1;
            if (line[i]=='-') { sign = -1; ++i; }
            long long val = 0;
            while (line[i]>='0' && line[i]<='9') { val = val*10 + (line[i]-'0'); ++i; }
            st.push(sign*val);
        } else {
            char op = line[i++];
            long long b = st.pop();
            long long a = st.pop();
            long long r = 0;
            if      (op=='+') r = a + b;
            else if (op=='-') r = a - b;
            else if (op=='*') r = a * b;
            else if (op=='/') r = b==0 ? 0 : a / b;   // integer division
            else if (op=='^') { long long p=1; for(int k=0;k<b;++k) p*=a; r=p; }
            st.push(r);
        }
    }

    cout << "Result = " << st.pop() << '\n';
    return 0;
}
