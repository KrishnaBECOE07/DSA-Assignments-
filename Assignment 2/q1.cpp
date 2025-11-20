#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key;
    cout << "Enter sorted array size: ";
    cin >> n;
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << "Enter key: ";
    cin >> key;

    int pos = binarySearch(arr, n, key);
    if (pos == -1) cout << "Not found\n";
    else cout << "Found at index " << pos << endl;
}
