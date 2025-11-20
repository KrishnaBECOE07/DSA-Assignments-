#include <iostream>
using namespace std;

const int MAX = 100;

struct Stack {
    int arr[MAX];
    int top;
    Stack() : top(-1) {}

    bool isEmpty() { return top == -1; }
    bool isFull()  { return top == MAX - 1; }

    void push(int x) {
        if (isFull()) { cout << "Stack overflow\n"; return; }
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) { cout << "Stack underflow\n"; return -1; }
        return arr[top--];
    }
    int peek() {
        if (isEmpty()) { cout << "Stack is empty\n"; return -1; }
        return arr[top];
    }
    void display() {
        if (isEmpty()) { cout << "[empty]\n"; return; }
        cout << "Stack (bottom -> top): ";
        for (int i = 0; i <= top; ++i) cout << arr[i] << ' ';
        cout << '\n';
    }
};

int main() {
    Stack st;
    while (true) {
        cout << "\n--- STACK MENU ---\n"
             << "1. push\n2. pop\n3. isEmpty\n4. isFull\n5. display\n6. peek\n7. exit\n"
             << "Choice: ";
        int ch; if (!(cin >> ch)) return 0;

        if (ch == 1) { int x; cout << "Value: "; cin >> x; st.push(x); }
        else if (ch == 2) { cout << "Popped: " << st.pop() << '\n'; }
        else if (ch == 3) { cout << (st.isEmpty() ? "true" : "false") << '\n'; }
        else if (ch == 4) { cout << (st.isFull()  ? "true" : "false") << '\n'; }
        else if (ch == 5) { st.display(); }
        else if (ch == 6) { cout << "Top: " << st.peek() << '\n'; }
        else if (ch == 7) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}
