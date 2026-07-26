#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string s){
    int i=s.length()-1;
    stack<string>st;

    while(i>=0){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();

            string added='('+t1+s[i]+t2+')';
            st.push(added);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    cout<<prefixToInfix(s);
    return 0;
}