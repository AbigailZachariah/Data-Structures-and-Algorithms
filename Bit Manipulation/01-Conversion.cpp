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

void convert2Decimal(string s){
    int len=s.size();
    int num=0;
    int p=1;
    for(int i=len-1;i>=0;i--){
        if(s[i]=='1'){
            num=num+p;
        }
        p=p*2;
    }
    cout<<"Decimal:"<<num;
}

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    convert2Binary(n);

    string s;
    cout<<"Enter the binary string:";
    cin>>s;    
    convert2Decimal(s);

    return 0;
}