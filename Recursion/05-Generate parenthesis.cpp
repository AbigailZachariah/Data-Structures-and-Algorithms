#include <bits/stdc++.h>
using namespace std;

void parenthesis(string curr, int open, int close, int n, vector<string> &res){
    if (curr.length() == 2 * n){
        res.push_back(curr);
        return;
    }

    if (open < n){
        parenthesis(curr + "(", open + 1, close, n, res);
    }
    if (close < open){
        parenthesis(curr + ")", open, close + 1, n, res);
    }
}

vector<string> generateParenthesis(int n){
    vector<string> res;
    parenthesis("", 0, 0, n, res);
    return res;
}

int main() {

    int n;
    cout<<"Enter the number of n:";
    cin>>n;

    vector<string> result;

    result=generateParenthesis(n);

    for (string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}