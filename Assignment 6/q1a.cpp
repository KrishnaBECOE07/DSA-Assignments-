#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    Node(int x): data(x), prev(NULL), next(NULL) {}
};

void display(Node* head){
    if(!head){ cout<<"NULL\n"; return; }
    Node* p=head;
    while(p){ cout<<p->data<<" <-> "; p=p->next; }
    cout<<"NULL\n";
}

void insertFront(Node* &head, Node* &tail, int x){
    Node* t=new Node(x);
    t->next=head;
    if(head) head->prev=t; else tail=t;
    head=t;
}
void insertBack(Node* &head, Node* &tail, int x){
    Node* t=new Node(x);
    t->prev=tail;
    if(tail) tail->next=t; else head=t;
    tail=t;
}
Node* find(Node* head,int key){
    while(head && head->data!=key) head=head->next;
    return head;
}
bool insertBefore(Node* &head, Node* &tail, int key, int x){
    Node* k=find(head,key);
    if(!k) return false;
    if(k==head){ insertFront(head,tail,x); return true; }
    Node* t=new Node(x);
    t->prev=k->prev; t->next=k;
    k->prev->next=t; k->prev=t;
    return true;
}
bool insertAfter(Node* &head, Node* &tail, int key, int x){
    Node* k=find(head,key);
    if(!k) return false;
    if(k==tail){ insertBack(head,tail,x); return true; }
    Node* t=new Node(x);
    t->next=k->next; t->prev=k;
    k->next->prev=t; k->next=t;
    return true;
}
bool deleteValue(Node* &head, Node* &tail, int key){
    Node* k=find(head,key);
    if(!k) return false;
    if(k==head) head=head->next;
    if(k==tail) tail=tail->prev;
    if(k->prev) k->prev->next=k->next;
    if(k->next) k->next->prev=k->prev;
    delete k; return true;
}
int searchPos(Node* head,int key){ int i=1; while(head){ if(head->data==key) return i; head=head->next; i++; } return -1; }
void clear(Node* &head){ while(head){ Node* t=head; head=head->next; delete t; } }

int main(){
    Node *head=NULL,*tail=NULL;
    while(true){
        cout<<"\n--- DOUBLY LINKED LIST MENU ---\n"
            <<"1.Insert first  2.Insert last  3.Insert BEFORE  4.Insert AFTER\n"
            <<"5.Delete value  6.Search  7.Display  8.Exit\nChoice: ";
        int ch; if(!(cin>>ch)) return 0;
        if(ch==1){ int x; cout<<"Value: "; cin>>x; insertFront(head,tail,x); }
        else if(ch==2){ int x; cout<<"Value: "; cin>>x; insertBack(head,tail,x); }
        else if(ch==3){ int key,x; cout<<"New value: "; cin>>x; cout<<"BEFORE which value? "; cin>>key;
                        if(!insertBefore(head,tail,key,x)) cout<<"Key not found\n"; }
        else if(ch==4){ int key,x; cout<<"New value: "; cin>>x; cout<<"AFTER which value? "; cin>>key;
                        if(!insertAfter(head,tail,key,x)) cout<<"Key not found\n"; }
        else if(ch==5){ int key; cout<<"Delete value: "; cin>>key; if(!deleteValue(head,tail,key)) cout<<"Not found\n"; }
        else if(ch==6){ int key; cout<<"Search value: "; cin>>key; int pos=searchPos(head,key);
                        if(pos==-1) cout<<"Not found\n"; else cout<<"Position from head: "<<pos<<'\n'; }
        else if(ch==7) display(head);
        else if(ch==8) break;
        else cout<<"Invalid\n";
    }
    clear(head); tail=NULL;
    return 0;
}
