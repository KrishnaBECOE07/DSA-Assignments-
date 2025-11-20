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
    int size(){ return cnt; }
};

struct Stack2Q {
    Queue q1, q2;
    bool empty(){ return q1.empty(); }
    void push(int x){
        q2.push(x);
        while(!q1.empty()) q2.push(q1.pop());
        // swap q1 and q2
        Queue tmp = q1; q1 = q2; q2 = tmp;
    }
    int pop(){
        if(q1.empty()){ cout<<"Underflow\n"; return -1; }
        return q1.pop();
    }
    int top(){
        if(q1.empty()){ cout<<"Empty\n"; return -1; }
        // front element of q1 is the top
        int v = q1.pop();
        // put it back at front: move others to q2 then rebuild
        q2.push(v);
        while(!q1.empty()) q2.push(q1.pop());
        Queue tmp=q1; q1=q2; q2=tmp;
        return v;
    }
    void display(){
        if(q1.empty()){ cout<<"[empty]\n"; return; }
        cout<<"Stack top->bottom: ";
        // transfer to q2 only to print in order
        int s=q1.size();
        for(int i=0;i<s;i++){
            int v=q1.pop();
            cout<<v<<' ';
            q2.push(v);
        }
        Queue tmp=q1; q1=q2; q2=tmp;
        cout<<'\n';
    }
};

int main(){
    Stack2Q st;
    while(true){
        cout<<"\n-- STACK USING TWO QUEUES --\n1.push 2.pop 3.top 4.display 5.exit\nChoice: ";
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
