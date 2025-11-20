#include <iostream>
using namespace std;

const int QMAX = 1000;

struct CharQueue {
    char a[QMAX]; int f, r, cnt;
    CharQueue(): f(0), r(0), cnt(0) {}
    bool empty(){ return cnt==0; }
    void push(char c){ if(cnt<QMAX){ a[r]=c; r=(r+1)%QMAX; cnt++; } }
    char front(){ return a[f]; }
    void pop(){ if(cnt){ f=(f+1)%QMAX; cnt--; } }
};

int main(){
    int m;
    cout<<"How many characters? "; cin>>m;
    CharQueue q;
    int freq[256]={0};

    for(int i=0;i<m;i++){
        char ch; cin>>ch;
        freq[(unsigned char)ch]++;
        q.push(ch);
        while(!q.empty() && freq[(unsigned char)q.front()] > 1) q.pop();
        if(q.empty()) cout<<"-1";
        else          cout<<q.front();
        if(i<m-1) cout<<' ';
    }
    cout<<'\n';
    return 0;
}
