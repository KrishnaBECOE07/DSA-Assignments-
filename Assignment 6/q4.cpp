#include <iostream>
using namespace std;

struct Node{ char ch; Node* prev; Node* next; Node(char c): ch(c), prev(NULL), next(NULL) {} };

int main(){
    int n; cout<<"Enter number of characters: "; cin>>n;
    Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        Node* t=new Node(c);
        t->prev=tail; if(tail) tail->next=t; else head=t; tail=t;
    }

    bool ok=true;
    Node* L=head; Node* R=tail;
    while(L && R && L!=R && R->next!=L){
        if(L->ch!=R->ch){ ok=false; break; }
        L=L->next; R=R->prev;
    }
    cout<<(ok? "True" : "False")<<'\n';

    while(head){ Node* t=head; head=head->next; delete t; }
    return 0;
}
