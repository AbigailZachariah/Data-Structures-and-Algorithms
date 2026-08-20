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

int main(){
    vector<int>nums;

    int n;
    cout<<"Enter the size of the arrays:\n";
    cin>>n;

    cout<<"Enter the elements:\n";
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }
    cout<<"Area:"<<largestRectangleArea(nums);
    return 0;
}