#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> nums, int n,int x){
    int ans=n;
    int low=0;
    int high=n-1;
    while(low<=high){
      int mid=(low+high)/2;
      if(nums[mid]>=x){
        ans=mid;
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }
    return ans;
}

int rowWithMax1s(vector < vector < int >> & mat) {
    int nRows=sizeof(mat)/sizeof(mat[0]);
    int ncol=sizeof(mat[0])/sizeof(mat[0][0]);
    int ind=-1;
    int cnt_max=0;
    for(int i=0;i<nRows;i++){
      int nOnes=ncol-lowerBound(mat[i],ncol,1);

      if(nOnes>cnt_max){
        cnt_max=nOnes;
        ind=i;
      }
    }
    return ind;
}

int main()
{
    int rows;
    int cols;

    
    cout << "Enter the number of rows:";
    cin >> rows;
    
    cout<<"Enter the number of columns:";
    cin >> cols;

    vector<vector<int>> mat(rows,vector<int>(cols));

    cout << "Enter the elements:";
    cout << endl;
    for (int i = 0; i < rows; i++){
        for(int j=0;j<cols;++j){
            cin>>mat[i][j];
        }
    }

    cout << "Row with Maximum ones:" << rowWithMax1s(mat);
    return 0;
}