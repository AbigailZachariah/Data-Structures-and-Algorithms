//The strings contain lowercase characters

#include<bits/stdc++.h>
using namespace std;

bool validAnagram(string s,string t){
    if(s.length()!=t.length()) return false;

    int freq[26]={0};

    for(int i=0;i<s.length();i++){
        freq[s[i]-'a']++;
    }
    for(int i=0;i<t.length();i++){
        freq[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(freq[i]!=0) return false;
    }
    return true;
}

int main(){
    string str1;
    string str2;
    cout<<"Enter the strings:";
    getline(cin,str1);
    getline(cin,str2);

    bool result = validAnagram(str1,str2);

    if(!result){
        cout<<"NOT Anagram";
    }
    else{
        cout<<"Anagram";
    }
    return 0;
}