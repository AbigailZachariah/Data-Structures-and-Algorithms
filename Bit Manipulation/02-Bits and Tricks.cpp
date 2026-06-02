#include <bits/stdc++.h>
using namespace std;

void convert2Binary(int n){
    string res="";
    while(n!=0){
        if(n%2==0)res+='0';
        else res+='1';
        n=n/2;
    }
    reverse(res.begin(),res.end());
    cout<<"Binary:"<<res<<endl;
}

//Swap two numbers
void swap(int &a, int &b) {
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a="<<a<<"  b="<<b<<endl;
}

//Check if ith bit is set or not
void checkIthBit(int n, int i) {
    if((n & (1<<i))!=0) cout<<"SET"<<endl;
    else cout<<"NOT SET"<<endl;
}

//Set the ith bit
void setIthBit(int n,int i){
    int N=(n | (i<<i));
    convert2Binary(N);
}

//Clear the ith Bit
void clearIthBit(int n,int i){
    int N=((n & ~(1<<i)));
    convert2Binary(N);
}

//Toggle ith bit
void toggleIthBit(int &n,int i){
    int N=((n ^(1<<i)));
    n=N;
    convert2Binary(N);
}

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;

    int n2;
    cout<<"Enter a number2:";
    cin>>n2;

    //swap(n,n2);
    checkIthBit(n,2);
    setIthBit(n,2);
    clearIthBit(n,2);
    toggleIthBit(n,2);

    return 0;
}