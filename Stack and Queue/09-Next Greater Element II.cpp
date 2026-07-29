#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int>nge(n);
    stack<int>st;

    //hypothetical array
    for(int i=(2*n)-1;i>=0;i-- ){
        while(!st.empty() && st.top()<=nums[i%n]) st.pop();

        if(i<n){ //find the next greater elements
            nge[i]=st.empty()?-1:st.top();
        }

        st.push(nums[i%n]);
    }
    return nge;
}

int main(){
    vector<int>nums1;

    int n1;
    cout<<"Enter the size of the arrays:\n";
    cin>>n1;

    cout<<"Enter the elements for nums1:\n";
    int ele1;
    for(int i=0;i<n1;i++){
        cin>>ele1;
        nums1.push_back(ele1);
    }

    vector<int>result=nextGreaterElements(nums1);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}