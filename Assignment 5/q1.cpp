#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(NULL) {}
};

void push_front(Node* &head, int x) {
    Node* t = new Node(x);
    t->next = head;
    head = t;
}

void push_back(Node* &head, int x) {
    Node* t = new Node(x);
    if (!head) { head = t; return; }
    Node* p = head;
    while (p->next) p = p->next;
    p->next = t;
}

bool insert_before(Node* &head, int key, int x) {
    if (!head) return false;
    if (head->data == key) { push_front(head, x); return true; }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (!p->next) return false;
    Node* t = new Node(x);
    t->next = p->next;
    p->next = t;
    return true;
}

bool insert_after(Node* head, int key, int x) {
    Node* p = head;
    while (p && p->data != key) p = p->next;
    if (!p) return false;
    Node* t = new Node(x);
    t->next = p->next;
    p->next = t;
    return true;
}

bool pop_front(Node* &head) {
    if (!head) return false;
    Node* t = head;
    head = head->next;
    delete t;
    return true;
}

bool pop_back(Node* &head) {
    if (!head) return false;
    if (!head->next) { delete head; head = NULL; return true; }
    Node* p = head;
    while (p->next->next) p = p->next;
    delete p->next;
    p->next = NULL;
    return true;
}

bool delete_value(Node* &head, int key) {
    if (!head) return false;
    if (head->data == key) { pop_front(head); return true; }
    Node* p = head;
    while (p->next && p->next->data != key) p = p->next;
    if (!p->next) return false;
    Node* t = p->next;
    p->next = t->next;
    delete t;
    return true;
}

int search_pos(Node* head, int key) { // 1-based index; -1 if not found
    int pos = 1;
    while (head) {
        if (head->data == key) return pos;
        head = head->next; pos++;
    }
    return -1;
}

void display(Node* head) {
    if (!head) { cout << "NULL\n"; return; }
    while (head) { cout << head->data << "->"; head = head->next; }
    cout << "NULL\n";
}

void clear_list(Node* &head) { while (head) pop_front(head); }

int main() {
    Node* head = NULL;
    while (true) {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n"
             << "1.Insert at beginning\n2.Insert at end\n"
             << "3.Insert BEFORE value\n4.Insert AFTER value\n"
             << "5.Delete from beginning\n6.Delete from end\n"
             << "7.Delete a specific value\n8.Search position\n9.Display\n10.Exit\n"
             << "Choice: ";
        int ch; if (!(cin >> ch)) return 0;

        if (ch == 1) { int x; cout << "Value: "; cin >> x; push_front(head, x); }
        else if (ch == 2) { int x; cout << "Value: "; cin >> x; push_back(head, x); }
        else if (ch == 3) { int key,x; cout << "Insert new value: "; cin >> x; cout << "BEFORE which value? "; cin >> key;
                             if (!insert_before(head, key, x)) cout << "Key not found\n"; }
        else if (ch == 4) { int key,x; cout << "Insert new value: "; cin >> x; cout << "AFTER which value? "; cin >> key;
                             if (!insert_after(head, key, x)) cout << "Key not found\n"; }
        else if (ch == 5) { if (!pop_front(head)) cout << "List empty\n"; }
        else if (ch == 6) { if (!pop_back(head)) cout << "List empty\n"; }
        else if (ch == 7) { int key; cout << "Delete value: "; cin >> key; if (!delete_value(head, key)) cout << "Not found\n"; }
        else if (ch == 8) { int key; cout << "Search value: "; cin >> key;
                             int pos = search_pos(head, key);
                             if (pos == -1) cout << "Not found\n"; else cout << "Position from head: " << pos << '\n'; }
        else if (ch == 9) display(head);
        else if (ch == 10) break;
        else cout << "Invalid choice\n";
    }
    clear_list(head);
    return 0;
}
