#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    int n=num.length();
    stack <char>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0') {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    
    if(st.empty()) return "0";
    
    string res="";
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    while(res.length()!=0 && res.back()=='0'){
        res.pop_back();
    }

    reverse(res.begin(),res.end());
    // if entire res is 0
    if(res.size()==0)return "0";
            
    return res;
}

int main(){
    string nums;

    int K;
    cout<<"Enter the value of K:\n";
    cin>>K;

    cout<<"Enter the string:";
    cin>>nums;

    cout<<removeKdigits(nums,K);
    return 0;
}