#include <bits/stdc++.h>
using namespace std;

int minBitFlips(int start, int goal) {
    int ans=start^goal;
    int cnt=0;
    for(int i=0;i<31;i++){
        if(ans & (1<<i))cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cout<<"Enter start:";
    cin>>n;

    int n2;
    cout<<"Enter goal:";
    cin>>n2;

    cout<<minBitFlips(n,n2);
    
    return 0;
}