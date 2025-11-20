#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter n (missing one number 1..n): ";
    cin >> n;
    cout << "Enter " << n - 1 << " elements:\n";
    for (int i = 0; i < n - 1; ++i) cin >> arr[i];

    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) sum += arr[i];
    cout << "Missing number = " << total - sum << endl;
}
