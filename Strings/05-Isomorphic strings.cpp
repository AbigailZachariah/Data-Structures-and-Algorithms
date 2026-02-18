//Two strings are isomorphic if the characters of one string can be replaced to get another string

#include<bits/stdc++.h>
using namespace std;

bool isomorphicStr(string s,string t){

    int m1[256]={0},m2[256]={0};

    int n=s.size();
    for(int i=0;i<n;i++){
        if(m1[s[i]]!=m2[t[i]]) return false;

        m1[s[i]]=i+1;
        m2[t[i]]=i+1;
    }
    return true;
}

int main(){
    string str1;
    string str2;
    cout<<"Enter the strings:";
    getline(cin,str1);
    getline(cin,str2);

    bool result = isomorphicStr(str1,str2);

    if(!result){
        cout<<"NOT isomorphic";
    }
    else{
        cout<<"Isomorphic";
    }
    return 0;
}