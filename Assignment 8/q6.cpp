#include <iostream>
using namespace std;

struct MaxPQ {
    int *a; int capacity; int size;
    MaxPQ(int cap = 100) : capacity(cap), size(0) { a = new int[capacity+1]; }
    ~MaxPQ() { delete [] a; }
    void push(int v) {
        if (size >= capacity) { cout << "Full\n"; return; }
        ++size; a[size] = v;
        int i = size;
        while (i > 1 && a[i/2] < a[i]) { swap(a[i/2], a[i]); i /= 2; }
    }
    int top() { if (size == 0) { cout << "Empty\n"; return INT_MIN; } return a[1]; }
    int pop() {
        if (size == 0) { cout << "Empty\n"; return INT_MIN; }
        int ret = a[1];
        a[1] = a[size]; --size;
        int i = 1;
        while (true) {
            int l = 2*i, r = 2*i+1, largest = i;
            if (l <= size && a[l] > a[largest]) largest = l;
            if (r <= size && a[r] > a[largest]) largest = r;
            if (largest == i) break;
            swap(a[i], a[largest]); i = largest;
        }
        return ret;
    }
    bool empty() { return size == 0; }
    void display() {
        cout << "Heap: ";
        for (int i = 1; i <= size; ++i) cout << a[i] << " ";
        cout << "\n";
    }
};

int main() {
    MaxPQ pq(50);
    pq.push(10); pq.push(5); pq.push(30); pq.push(20);
    pq.display();
    cout << "Top: " << pq.top() << "\n";
    cout << "Pop: " << pq.pop() << "\n";
    pq.display();
    return 0;
}
