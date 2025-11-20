#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue {
    int a[MAX];
    int front, rear; // front points to current first; rear to last
    Queue() : front(0), rear(-1) {}

    bool isEmpty() { return front > rear; }
    bool isFull()  { return rear == MAX - 1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue overflow\n"; return; }
        a[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue underflow\n"; return -1; }
        return a[front++];
    }
    int peek() {
        if (isEmpty()) { cout << "Queue empty\n"; return -1; }
        return a[front];
    }
    void display() {
        if (isEmpty()) { cout << "[empty]\n"; return; }
        cout << "Queue: ";
        for (int i = front; i <= rear; ++i) cout << a[i] << ' ';
        cout << '\n';
    }
};

int main() {
    Queue q;
    while (true) {
        cout << "\n-- SIMPLE QUEUE MENU --\n"
             << "1.enqueue  2.dequeue  3.isEmpty  4.isFull  5.display  6.peek  7.exit\n"
             << "Choice: ";
        int ch; if (!(cin >> ch)) return 0;
        if (ch == 1) { int x; cout << "Value: "; cin >> x; q.enqueue(x); }
        else if (ch == 2) { cout << "Dequeue: " << q.dequeue() << '\n'; }
        else if (ch == 3) { cout << (q.isEmpty() ? "true\n" : "false\n"); }
        else if (ch == 4) { cout << (q.isFull()  ? "true\n" : "false\n"); }
        else if (ch == 5) q.display();
        else if (ch == 6) { cout << "Front: " << q.peek() << '\n'; }
        else if (ch == 7) break;
        else cout << "Invalid\n";
    }
    return 0;
}
