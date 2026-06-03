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

//  Remove the rightmost bit
void removeLastSetBit(int n){
    int N=n & (n-1);
    convert2Binary(N);
}

//Check if number is power of 2
void isPowerOfTwo(int n) {
    if(n<=0) cout<<"Not a power of 2"<<endl;
    else{
        if((n & (n-1))==0){
            cout<<"Power of 2"<<endl;
        }
        else cout<<"Not a power of 2"<<endl;
    }
}

//Number of set Bits
int cntofSetBits(int n){
    int cnt=0;
    while(n!=0){
        n=n & (n-1);
        cnt++;
    }
    return cnt;
}
 
//Check if number is odd or not
void isOdd(int n) {
    if((n & 1) ==1) cout<<"Is odd"<<endl;
    else cout<<"Not odd"<<endl;
}

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;

    int n2;
    cout<<"Enter a number2:";
    cin>>n2;

    removeLastSetBit(n);
    isPowerOfTwo(n2);
    cout<<"Number of set bits:"<<cntofSetBits(n)<<endl;
    isOdd(n2);

    return 0;
}