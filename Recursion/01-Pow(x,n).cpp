#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long nn=n;
    double ans=1.0;

    if(nn<0) nn=-1*nn;
    while(nn){
        if(nn%2==0){
            x=x*x;
            nn=nn/2;
        }
        else{
            ans=ans*x;
            nn=nn-1;
        }
    }
    if(n<0){
        ans=(double)1.0/(double)(ans);
    }
    return ans;
}

int main(){
    double num;
    cout<<"Enter the number:";
    cin>>num;

    int n;
    cout<<"Enter the power:";
    cin>>n;

    cout<<myPow(num,n);
    return 0;
}