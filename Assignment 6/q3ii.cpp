#include <iostream>
using namespace std;
struct Node{ int d; Node* next; Node(int x): d(x), next(NULL) {} };
int main(){
    int n; cout<<"Enter n: "; cin>>n;
    Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){ int x; cin>>x; Node* t=new Node(x);
        if(!head){ head=tail=t; } else { tail->next=t; tail=t; } }
    if(head) tail->next=head;

    int cnt=0;
    if(head){ Node* p=head; do{ cnt++; p=p->next; }while(p!=head); }
    cout<<"Size (CLL) = "<<cnt<<'\n';

    if(head){ Node* p=head->next; while(p!=head){ Node* t=p; p=p->next; delete t; } delete head; }
    return 0;
}
