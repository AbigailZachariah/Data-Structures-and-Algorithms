#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    if(strs.empty()) return " ";
        
    sort(strs.begin(),strs.end());

    string first=strs[0];
    string last=strs[strs.size()-1];

    int minLength=min(first.size(),last.size());

    for(int i=0;i<minLength;i++){
        if(first[i]!=last[i])break;
        ans+=first[i];
    }
    return ans;
}

int main()
{
    vector<string> str;

    int n;
    cout << "Enter the number of elements:";
    cin>>n;

    string s;
    cout<<"Enter the strings:";
    cout<<endl;
    for(int i=0;i<n;i++){
        cin>>s;
        str.push_back(s);
    }

    cout << longestCommonPrefix(str);
    return 0;
}