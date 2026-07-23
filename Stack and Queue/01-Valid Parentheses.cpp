#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int n=s.length();
    stack<char>st;
    
    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else {
            if(st.empty())return false; //NO match found
            else{
                char ch=st.top();
                st.pop();

                if((s[i]==')' && ch=='(' ) || (s[i]==']'&& ch=='[') || (s[i]=='}'&& ch=='{') ){ }
                
                else return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    cout<<isValid(s);
    return 0;
}