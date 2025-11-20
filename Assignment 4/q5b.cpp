#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue {
    int a[MAX], f, r, cnt;
    Queue(): f(0), r(0), cnt(0) {}
    bool empty(){ return cnt==0; }
    bool full(){ return cnt==MAX; }
    void push(int x){ if(!full()){ a[r]=x; r=(r+1)%MAX; cnt++; } }
    int pop(){ if(empty()) return -1; int v=a[f]; f=(f+1)%MAX; cnt--; return v; }
    int front(){ return empty()? -1 : a[f]; }
    int size(){ return cnt; }
};

struct Stack1Q {
    Queue q;
    void push(int x){
        q.push(x);
        int s = q.size();
        // rotate previous s-1 elements to back so x becomes at front
        for(int i=0;i<s-1;i++) q.push(q.pop());
    }
    int pop(){
        if(q.empty()){ cout<<"Underflow\n"; return -1; }
        return q.pop();
    }
    int top(){
        if(q.empty()){ cout<<"Empty\n"; return -1; }
        return q.front();
    }
    void display(){
        if(q.empty()){ cout<<"[empty]\n"; return; }
        cout<<"Stack top->bottom: ";
        int s=q.size();
        for(int i=0;i<s;i++){
            int v=q.pop(); cout<<v<<' '; q.push(v);
        }
        cout<<'\n';
    }
};

int main(){
    Stack1Q st;
    while(true){
        cout<<"\n-- STACK USING ONE QUEUE --\n1.push 2.pop 3.top 4.display 5.exit\nChoice: ";
        int ch; if(!(cin>>ch)) return 0;
        if(ch==1){ int x; cout<<"Value: "; cin>>x; st.push(x); }
        else if(ch==2){ cout<<"Popped: "<<st.pop()<<'\n'; }
        else if(ch==3){ cout<<"Top: "<<st.top()<<'\n'; }
        else if(ch==4) st.display();
        else if(ch==5) break;
        else cout<<"Invalid\n";
    }
    return 0;
}
