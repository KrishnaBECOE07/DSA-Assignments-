#include <iostream>
using namespace std;

struct Node{ int d; Node* next; Node(int x): d(x), next(NULL) {} };

bool isCircular(Node* head){
    if(!head) return false;
    Node* slow=head; Node* fast=head->next;
    while(fast && fast->next){
        if(slow==fast) return true;
        slow=slow->next; fast=fast->next->next;
    }
    return false;
}

int main(){
    int n; cout<<"Enter n: "; cin>>n;
    Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){ int x; cin>>x; Node* t=new Node(x);
        if(!head){ head=tail=t; } else { tail->next=t; tail=t; } }

    cout<<"Make it circular? (0/1): ";
    int flag; cin>>flag;
    if(flag && tail) tail->next=head; // close the loop

    cout<<(isCircular(head) ? "Circular" : "Not Circular")<<'\n';

    // free (break the loop if needed)
    if(tail && tail->next==head) tail->next=NULL;
    while(head){ Node* t=head; head=head->next; delete t; }
    return 0;
}
