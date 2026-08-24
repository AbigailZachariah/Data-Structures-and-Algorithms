#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M){
    int n=M.size();

    int top=0;
    int down=n-1;

    while(top<down){
        if(M[top][down]==1)top++;
        else if(M[down][top]=1)down--;
        else {
            top++;
            down--;
        }
    }
    if(top>down)return-1;

    for(int i=0;i<n;i++){
        if(top==i)continue;// diagonal
        if(M[top][i]==0 && M[i][top]==1){}
        else return-1;
    }
    return top;
}

int main(){
    vector<vector<int>> M = {
        {0, 1, 1, 0}, 
        {0, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 0}
    };
    cout << "The index of celebrity is: " << celebrity(M);
    return 0;
}