#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){
    string result = "";
    int level = 0;

    for (char ch : s){
        if (ch == '('){
            if (level > 0){
                result += ch;
            }
            level++;
        }
        else if (ch == ')'){
            level--;
            if (level > 0){ //checking if still inside a primitive
                result += ch;
            }
        }
    }
    return result;
}

int main(){
    string str;
    cout<<"Enter a parentheses string:";
    cin>>str;

    cout<<removeOuterParentheses(str);
    return 0;
}