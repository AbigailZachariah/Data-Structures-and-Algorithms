#include <bits/stdc++.h>
using namespace std;

int maxIndex(vector<vector<int>> &mat, int n, int m, int col){
    int maxEl = -1;
    int ind = -1;
    for (int i = 0; i < n; i++){
        if (mat[i][col] > maxEl){
            maxEl = mat[i][col];
            ind = i;
        }
    }
    return ind;
}
vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high){
        int mid = (low + high) / 2;
        int maxRowIndex = maxIndex(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;

        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main(){
    int nrow;
    int ncol;

    cout<<"Enter number of rows and columns:"<<endl;
    cin>>nrow;
    cin>>ncol;

    vector<vector<int>>mat(nrow,vector<int>(ncol));

    cout<<"Enter the elements:"<<endl;

    for(int i=0;i<nrow;i++){
        for(int j=0;j<ncol;j++){
            cin>>mat[i][j];
        }
    }
    vector result=findPeakGrid(mat);
    cout<<"Row: "<<result[0]<<" Column: "<<result[1];
    return 0;
}