#include<bits/stdc++.h>
using namespace std;

const int INT_MIN_VAL=-2147483648;
const int INT_MAX_VAL=2147483647;

int strInt(const string &s,int i,long long num,int sign){

    if(i>=s.size() || !isdigit(s[i])){
        return (int)(sign*num);
    }

    num=num*10+(s[i]-'0');

    if(sign*num <= INT_MIN_VAL) return INT_MIN_VAL;
    if(sign*num >= INT_MAX_VAL) return INT_MAX_VAL;

    return strInt(s,i+1,num,sign);
}

int Atoi(string s ,int i=0){
    while(i<s.size() && s[i]==' ') i++;

    int sign=1;
    if(i<s.size() && (s[i]=='+'||s[i]=='-')){
        sign=(s[i]=='-')? -1 : 1;
        i++;
    }
    return strInt(s,i,0,sign);
}

int main(){
    string str;
    cout<<"Enter the string:";
    cin>>str;

    cout<<"The integer value:"<<Atoi(str);
    return 0;
}