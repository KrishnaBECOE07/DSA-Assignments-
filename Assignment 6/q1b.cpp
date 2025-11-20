#include <iostream>
using namespace std;

struct Node{
    int data; Node* next;
    Node(int x): data(x), next(NULL) {}
};

void display(Node* head){
    if(!head){ cout<<"[empty]\n"; return; }
    Node* p=head;
    do{ cout<<p->data<<" -> "; p=p->next; } while(p!=head);
    cout<<head->data<<" (back to head)\n";
}

Node* find(Node* head,int key){
    if(!head) return NULL;
    Node* p=head;
    do{ if(p->data==key) return p; p=p->next; } while(p!=head);
    return NULL;
}

void insertFront(Node* &head, int x){
    Node* t=new Node(x);
    if(!head){ head=t; t->next=t; return; }
    Node* tail=head; while(tail->next!=head) tail=tail->next;
    t->next=head; tail->next=t; head=t;
}
void insertBack(Node* &head, int x){
    Node* t=new Node(x);
    if(!head){ head=t; t->next=t; return; }
    Node* tail=head; while(tail->next!=head) tail=tail->next;
    tail->next=t; t->next=head;
}
bool insertAfter(Node* &head,int key,int x){
    Node* k=find(head,key); if(!k) return false;
    Node* t=new Node(x); t->next=k->next; k->next=t;
    return true;
}
bool insertBefore(Node* &head,int key,int x){
    if(!head) return false;
    if(head->data==key){ insertFront(head,x); return true; }
    Node* p=head;
    do{
        if(p->next->data==key){ Node* t=new Node(x); t->next=p->next; p->next=t; return true; }
        p=p->next;
    }while(p!=head);
    return false;
}
bool deleteValue(Node* &head,int key){
    if(!head) return false;
    Node* p=head; Node* prev=NULL;
    do{
        if(p->data==key){
            if(p==head){
                if(head->next==head){ delete head; head=NULL; return true; }
                Node* tail=head; while(tail->next!=head) tail=tail->next;
                head=head->next; tail->next=head; delete p; return true;
            } else {
                prev->next=p->next; delete p; return true;
            }
        }
        prev=p; p=p->next;
    }while(p!=head);
    return false;
}
int searchPos(Node* head,int key){ if(!head) return -1; int pos=1; Node* p=head;
    do{ if(p->data==key) return pos; p=p->next; pos++; }while(p!=head);
    return -1;
}
void clear(Node* &head){ if(!head) return; Node* p=head->next; while(p!=head){ Node* t=p; p=p->next; delete t; } delete head; head=NULL; }

int main(){
    Node* head=NULL;
    while(true){
        cout<<"\n--- CIRCULAR LIST MENU ---\n"
            <<"1.Insert first  2.Insert last  3.Insert BEFORE  4.Insert AFTER\n"
            <<"5.Delete value  6.Search  7.Display  8.Exit\nChoice: ";
        int ch; if(!(cin>>ch)) return 0;
        if(ch==1){ int x; cout<<"Value: "; cin>>x; insertFront(head,x); }
        else if(ch==2){ int x; cout<<"Value: "; cin>>x; insertBack(head,x); }
        else if(ch==3){ int key,x; cout<<"New value: "; cin>>x; cout<<"BEFORE which value? "; cin>>key;
                        if(!insertBefore(head,key,x)) cout<<"Key not found\n"; }
        else if(ch==4){ int key,x; cout<<"New value: "; cin>>x; cout<<"AFTER which value? "; cin>>key;
                        if(!insertAfter(head,key,x)) cout<<"Key not found\n"; }
        else if(ch==5){ int key; cout<<"Delete value: "; cin>>key; if(!deleteValue(head,key)) cout<<"Not found\n"; }
        else if(ch==6){ int key; cout<<"Search value: "; cin>>key; int pos=searchPos(head,key);
                        if(pos==-1) cout<<"Not found\n"; else cout<<"Position from head: "<<pos<<'\n'; }
        else if(ch==7) display(head);
        else if(ch==8) break;
        else cout<<"Invalid\n";
    }
    clear(head);
    return 0;
}
