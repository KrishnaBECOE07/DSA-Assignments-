#include <iostream>
using namespace std;

struct Node{ int data; Node* next; Node(int x): data(x), next(NULL) {} };

int main(){
    int n; cout<<"Enter n: "; cin>>n;
    if(n<=0){ cout<<"\n"; return 0; }

    // build circular list from input
    Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        Node* t=new Node(x);
        if(!head){ head=tail=t; }
        else { tail->next=t; tail=t; }
    }
    tail->next=head; // make circular

    // display with head value again at end
    Node* p=head;
    do{ cout<<p->data<<' '; p=p->next; } while(p!=head);
    cout<<head->data<<'\n';

    // free
    p=head->next; while(p!=head){ Node* t=p; p=p->next; delete t; } delete head;
    return 0;
}
