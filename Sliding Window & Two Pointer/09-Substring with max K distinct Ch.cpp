#include <bits/stdc++.h>
using namespace std; 

int kDistinctChar(string& s, int k) {
    int n=s.size();
    int l=0;
    int r=0;
    int maxLen=0;

    map<char,int>mpp;

    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
        }
        if(mpp.size()<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
}


int main(){
    string s;
    cout<<"Enter string:";
    cin>>s;

    int k;
    cout<<"Enter k:";
    cin>>k;

    cout<<kDistinctChar(s,k);
    return 0;
}