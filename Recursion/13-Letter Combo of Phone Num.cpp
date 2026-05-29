#include <bits/stdc++.h>
using namespace std;


void func(int ind,string digits,string s,vector<string>&ans,string combos[]){
    if(ind==digits.size()){
        ans.push_back(s);
        return;
    }
    //converting character to digit
    int digit=digits[ind]-'0';

    for(int i=0;i<combos[digit].size();i++){
        func(ind+1,digits,s+combos[digit][i],ans,combos);
    }
}   

vector<string> letterCombinations(string digits) {
    string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    string s="";
    func(0,digits,s,ans,combos);
    return ans;
}

int main() {

    string nums;

    cout<<"Enter the string :";
    getline(cin,nums);

    vector<string>result=letterCombinations(nums);

    for(auto vec:result){
            cout<<vec<<" ";
    }

    return 0;
}