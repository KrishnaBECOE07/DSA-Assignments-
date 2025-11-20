#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter n (missing one number 1..n): ";
    cin >> n;
    cout << "Enter sorted " << n - 1 << " elements:\n";
    for (int i = 0; i < n - 1; ++i) cin >> arr[i];

    int l = 0, r = n - 2, missing = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == mid + 1) l = mid + 1;
        else { missing = mid + 1; r = mid - 1; }
    }
    cout << "Missing number = " << missing << endl;
}
