#include <iostream>
using namespace std;

int main(){
    const int MAX=200;
    int n, a[MAX];
    cout<<"Enter even n: "; cin>>n;
    cout<<"Enter "<<n<<" elements:\n";
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<"Interleaved: ";
    int mid=n/2;
    for(int i=0;i<mid;i++){
        cout<<a[i]<<' '<<a[mid+i]<<' ';
    }
    cout<<'\n';
    return 0;
}
