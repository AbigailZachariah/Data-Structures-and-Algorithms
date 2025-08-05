#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s)
{
    string temp=s;
    int n=s.length();
	for (int i=0;i<n/2;i++){
        swap(temp[i],temp[n-i-1]);
    }
    if(s==temp) return true;
    else return false;    
}

int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    bool result=isPalindrome(s);

    if(result==false) cout<<"NOT A PALINDROME";
    else cout<<"PALINDROME";
    return 0;
}