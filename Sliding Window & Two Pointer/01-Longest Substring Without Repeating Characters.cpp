#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n=s.length();

    int hash[256];
    int l=0;
    int r=0;
    int maxLen=0;

    for (int i = 0; i < 256; ++i) {
        hash[i] = -1;
    }

    while(r<n){
        //present in array
        if(hash[s[r]]!=-1){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        int len=r-l+1;
        maxLen=max(len,maxLen);
        //updating hash
        hash[s[r]]=r;
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    cin>>s;

    cout<<lengthOfLongestSubstring(s);
    return 0;
}