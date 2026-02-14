#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high){
        int mid = (low+high) / 2;
        if (arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int smallestEquals(vector<vector<int>> &mat, int n, int m, int x){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cnt += upperBound(mat[i], m, x);
    }
    return cnt;
}

int findMedian(vector<vector<int>> &matrix){
    int low = INT_MAX;
    int high = INT_MIN;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }
    int req = (m * n) / 2;
    while (low <= high){
        int mid = (low + high) / 2;
        int smalleq= smallestEquals(matrix, n, m, mid);
        if (smalleq <= req){
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
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
    cout<<"Median:"<<findMedian(mat);
    return 0;
}