#include <iostream>
using namespace std;

const int MAX = 100;

struct CQueue {
    int a[MAX];
    int front, rear, cnt; // track count to simplify full/empty
    CQueue(): front(0), rear(0), cnt(0) {}

    bool isEmpty(){ return cnt == 0; }
    bool isFull(){ return cnt == MAX; }

    void enqueue(int x){
        if(isFull()){ cout << "Queue overflow\n"; return; }
        a[rear] = x;
        rear = (rear + 1) % MAX;
        cnt++;
    }
    int dequeue(){
        if(isEmpty()){ cout << "Queue underflow\n"; return -1; }
        int v = a[front];
        front = (front + 1) % MAX;
        cnt--;
        return v;
    }
    int peek(){
        if(isEmpty()){ cout << "Queue empty\n"; return -1; }
        return a[front];
    }
    void display(){
        if(isEmpty()){ cout << "[empty]\n"; return; }
        cout << "Queue: ";
        for(int i=0;i<cnt;i++){
            int idx = (front + i) % MAX;
            cout << a[idx] << ' ';
        }
        cout << '\n';
    }
};

int main(){
    CQueue q;
    while(true){
        cout << "\n-- CIRCULAR QUEUE MENU --\n"
             << "1.enqueue  2.dequeue  3.isEmpty  4.isFull  5.display  6.peek  7.exit\n"
             << "Choice: ";
        int ch; if(!(cin>>ch)) return 0;
        if(ch==1){ int x; cout<<"Value: "; cin>>x; q.enqueue(x); }
        else if(ch==2){ cout<<"Dequeue: "<<q.dequeue()<<'\n'; }
        else if(ch==3){ cout<<(q.isEmpty()?"true\n":"false\n"); }
        else if(ch==4){ cout<<(q.isFull() ?"true\n":"false\n"); }
        else if(ch==5) q.display();
        else if(ch==6){ cout<<"Front: "<<q.peek()<<'\n'; }
        else if(ch==7) break;
        else cout<<"Invalid\n";
    }
    return 0;
}
