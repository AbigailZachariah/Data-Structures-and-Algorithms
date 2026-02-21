#include<bits/stdc++.h>
using namespace std;

int maxKDistinct(string s,int k){
    int left=0,res=0;
    unordered_map<char,int>freq;
    for(int right=0;right<s.size();right++){
        freq[s[right]]++;

        while(freq.size()>k){
            freq[s[left]]--;
            if(freq[s[left]]==0){
                freq.erase(s[left]);
            }
            left++;
        }
        res+=right-left+1;
    }
    return res;
}

int countSubstrings(string s,int k){
    return maxKDistinct(s,k)-maxKDistinct(s,k-1);
}

int main(){
    string str;
    int K;    

    cout<<"Enter the number of distinct characters:";
    cin>>K;

    cout<<"Enter the string:";
    cin>>str;

    cout<<"Number of Substrings:"<<countSubstrings(str,K);
    return 0;
}