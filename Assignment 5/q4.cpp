#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int x): data(x), next(NULL) {} };

void push_back(Node* &head, int x){
    Node* t=new Node(x);
    if(!head){ head=t; return; }
    Node* p=head; while(p->next) p=p->next; p->next=t;
}

void display(Node* head){
    while(head){ cout<<head->data<<"->"; head=head->next; }
    cout<<"NULL\n";
}

Node* reverse(Node* head){
    Node *prev=NULL, *cur=head, *nxt=NULL;
    while(cur){
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

int main(){
    int n; Node* head=NULL;
    cout<<"Enter n: "; cin>>n;
    cout<<"Enter "<<n<<" values:\n";
    for(int i=0;i<n;i++){ int x; cin>>x; push_back(head,x); }

    cout<<"Original: "; display(head);
    head = reverse(head);
    cout<<"Reversed: "; display(head);

    while(head){ Node* t=head; head=head->next; delete t; }
    return 0;
}
