#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int x): data(x), next(NULL) {} };

void push_back(Node* &head, int x){
    Node* t = new Node(x);
    if(!head){ head = t; return; }
    Node* p=head; while(p->next) p=p->next; p->next=t;
}

int delete_all(Node* &head, int key){
    int cnt = 0;
    // remove from head while matches
    while(head && head->data == key){ Node* t=head; head=head->next; delete t; cnt++; }
    if(!head) return cnt;
    Node* p = head;
    while(p->next){
        if(p->next->data == key){ Node* t=p->next; p->next=t->next; delete t; cnt++; }
        else p = p->next;
    }
    return cnt;
}

void display(Node* head){
    if(!head){ cout << "NULL\n"; return; }
    while(head){ cout<<head->data; if(head->next) cout<<"->"; head=head->next; }
    cout<<"->NULL\n";
}

int main(){
    int n, key; Node* head=NULL;
    cout << "Enter n: "; cin >> n;
    cout << "Enter " << n << " values:\n";
    for(int i=0;i<n;i++){ int x; cin>>x; push_back(head,x); }
    cout << "Key to delete: "; cin >> key;

    int count = 0;
    // also count occurrences before deletion (optional — matches problem statement)
    Node* p=head; while(p){ if(p->data==key) count++; p=p->next; }

    int removed = delete_all(head, key); // removed == count
    cout << "Count: " << count << "\nUpdated List: ";
    display(head);

    // free list
    while(head){ Node* t=head; head=head->next; delete t; }
    return 0;
}
