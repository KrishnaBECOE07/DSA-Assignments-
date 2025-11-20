#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int x): data(x), next(NULL) {} };

void push_back(Node* &head, int x){
    Node* t=new Node(x);
    if(!head){ head=t; return; }
    Node* p=head; while(p->next) p=p->next; p->next=t;
}

int main(){
    int n; Node* head=NULL;
    cout<<"Enter n: "; cin>>n;
    cout<<"Enter "<<n<<" values:\n";
    for(int i=0;i<n;i++){ int x; cin>>x; push_back(head,x); }

    if(!head){ cout<<"List empty\n"; return 0; }

    Node *slow=head, *fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }
    cout<<"Middle element: "<<slow->data<<'\n';

    while(head){ Node* t=head; head=head->next; delete t; }
    return 0;
}
