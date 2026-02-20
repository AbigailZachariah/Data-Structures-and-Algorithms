#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s){
    int cnt=0,max_depth=0;
    for(char ch:s){
        if(ch=='(') cnt++;
        else if(ch==')') cnt--;
        max_depth=max(max_depth,cnt);
    }
    return max_depth;
}

int main(){
    string str;
    cout<<"Enter the string:";
    cin>>str;

    cout<<"Maximum Nesting Depth:"<<maxDepth(str);
    return 0;
}