#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int hash[256]={0};
    int n=s.size();
    int m=t.size();
    if(n<m)return "";

    int minLen=INT_MAX;
    int sInd=-1,cnt=0,l=0,r=0;       
    for(int i=0;i<m;i++){
        hash[t[i]]++;
    }

    while(r<n){
        if(hash[s[r]]>0){
            cnt++;
        }
        hash[s[r]]--;

        while(cnt==m){
            if(r-l+1<minLen){
                minLen=r-l+1;
                sInd=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)cnt--;
            l++;
        }
        r++;
    }
    return sInd==-1?"":s.substr(sInd,minLen);
}

int main(){
    string s;
    cout<<"Enter string:";
    cin>>s;

    string t;
    cout<<"Enter string:";
    cin>>t;

    cout<<minWindow(s,t);
    return 0;
}