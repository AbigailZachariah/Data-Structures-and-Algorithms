#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int l=0;
    int r=0;
    int maxLen=0;
    int max_fq=0;
    int hash[26]={0};

    while(r<s.length()){
        hash[s[r]-'A']++;
        max_fq=max(max_fq,hash[s[r]-'A']);

        if((r-l+1)-max_fq>k){ //number of replacement required
            hash[s[l]-'A']--;
            max_fq=0;
            l++;
        }

        if((r-l+1)-max_fq<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;

    int k;
    cout<<"Enter k:";
    cin>>k;

    cout<<characterReplacement(s,k);
    return 0;
}