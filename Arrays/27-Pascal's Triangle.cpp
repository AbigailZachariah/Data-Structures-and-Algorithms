#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

//lists of lists
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    vector<vector<int>> arr;
    
    int numRows;
    cout<<"Enter the number of rows to be printed:";
    cin>>numRows;

    arr=pascalTriangle(numRows);
    for(auto list1:arr){
       for(auto list2:list1){
        cout<<list2<<" ";
       }
       cout<<endl;
    }
    return 0;
}
