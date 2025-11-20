#include <iostream>
using namespace std;
struct Node{ int d; Node* prev; Node* next; Node(int x): d(x), prev(NULL), next(NULL) {} };
int main(){
    int n; cout<<"Enter n: "; cin>>n;
    Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){ int x; cin>>x; Node* t=new Node(x);
        t->prev=tail; if(tail) tail->next=t; else head=t; tail=t; }
    int cnt=0; for(Node* p=head;p;p=p->next) cnt++;
    cout<<"Size (DLL) = "<<cnt<<'\n';
    while(head){ Node* t=head; head=head->next; delete t; }
    return 0;
}
