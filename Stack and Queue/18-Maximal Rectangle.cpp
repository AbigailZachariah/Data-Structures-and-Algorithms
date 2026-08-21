#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int>st;
    int maxArea=0;
    for(int i=0;i<n;i++){
        while(!st.empty()&& heights[st.top()]> heights[i]){
            int ele=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,heights[ele]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
        int ele=st.top();
        st.pop();
        int nse=n;
        int pse=st.empty()?-1:st.top();
        maxArea=max(maxArea,heights[ele]*(nse-pse-1));
    }
    return maxArea;
}
int maximalRectangle(vector<vector<char>>& matrix) {

    if (matrix.empty()) return 0;

    int maxArea=0;
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int>heights(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1')heights[j]++; // vector is character
            else heights[j]=0;
        }
        int area=largestRectangleArea(heights);
        maxArea=max(maxArea,area);
    }
        
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}