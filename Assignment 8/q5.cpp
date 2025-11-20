#include <iostream>
using namespace std;

// We'll use 1-indexed helper array for heap operations.
void heapify_down_max(int a[], int n, int i) {
    int largest = i;
    int l = 2*i, r = 2*i + 1;
    if (l <= n && a[l] > a[largest]) largest = l;
    if (r <= n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify_down_max(a, n, largest);
    }
}
void build_max_heap(int a[], int n) { for (int i = n/2; i >= 1; --i) heapify_down_max(a, n, i); }

void heapsort_ascending(int arr0[], int n0) {
    // copy to 1..n array
    int *a = new int[n0 + 1];
    for (int i = 0; i < n0; ++i) a[i+1] = arr0[i];
    int n = n0;
    build_max_heap(a, n);
    for (int i = n; i >= 2; --i) {
        swap(a[1], a[i]);
        --n;
        heapify_down_max(a, n, 1);
    }
    for (int i = 0; i < n0; ++i) arr0[i] = a[i+1];
    delete [] a;
}

void heapsort_descending(int arr[], int n) {
    heapsort_ascending(arr, n);
    for (int i = 0; i < n/2; ++i) swap(arr[i], arr[n-1-i]);
}

int main() {
    cout << "Enter n: ";
    int n; cin >> n;
    int *arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    heapsort_ascending(arr, n);
    cout << "Ascending: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";

    // Demonstrate descending:
    heapsort_descending(arr, n);
    cout << "Descending: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";
    delete [] arr;
    return 0;
}
