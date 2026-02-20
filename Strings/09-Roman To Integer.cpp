#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s){

    int res = 0;
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < s.size() - 1; i++){
        if (roman[s[i]] < roman[s[i + 1]]){ //checking if the value of the current char is less than the next
            res -= roman[s[i]];  // Considering as a subtractive pair
        }
        else{
            res += roman[s[i]]; //adding it normally
        }
    }
    return res + roman[s.back()];  //adding the value of the last char since there is nothing after it 
}

int main(){
    string str;
    cout<<"Enter the string:";
    cin>>str;

    cout<<"The integer value:"<<romanToInt(str);
    return 0;
}