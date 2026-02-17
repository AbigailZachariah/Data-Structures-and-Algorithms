#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s){

    int i = s.size();
    string result = "";

    while (i >= 0){
        while (i >= 0 && s[i] == ' '){
            i--;
        }
        if (i < 0)
            break;

        int end = i;
        while (i >= 0 && s[i] != ' '){ // when space encountered
            i--;
        }

        string word = s.substr(i + 1, end - i);

        if (!result.empty()){
            result += ' ';
        }
        result += word;
    }
    return result;
}

int main(){
    string str;
    cout << "Enter a string:";
    getline(cin,str);

    cout << reverseWords(str);
    return 0;
}