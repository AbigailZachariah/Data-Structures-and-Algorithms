#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;

    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (matrix[mid / m][mid % m] == target){
            return true;
        }
        if (matrix[mid / m][mid % m] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

int main(){
    int nrow;
    int ncol;
    int target;

    cout<<"Enter number of rows and columns:"<<endl;
    cin>>nrow;
    cin>>ncol;

    cout<<"Enter the target value:";
    cin>>target;

    vector<vector<int>>mat(nrow,vector<int>(ncol));

    cout<<"Enter the elements:"<<endl;

    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncol;j++){
            cin>>mat[i][j];
        }
    }
    bool result=searchMatrix(mat,target);
    if(!result){
        cout<<"Element not found";
    }
    else {
        cout<<"Search successful";
    }
    return 0;
}