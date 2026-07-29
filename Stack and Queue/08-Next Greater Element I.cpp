#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n2=nums2.size();
    vector<int>nge(nums2.size());
    stack <int>st;
    
    for(int i=n2-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i])st.pop();
        if(st.empty())nge[i]=-1;
        else nge[i]=st.top();

        st.push(nums2[i]);
    }

    vector<int>result(nums1.size());
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<n2;j++){
            if(nums1[i]==nums2[j]){
                result[i]=nge[j];
                break;
            }
        }
    }
    return result;
}

int main(){
    vector<int>nums1;
    vector<int>nums2;

    int n1,n2;
    cout<<"Enter the size of the arrays:\n";
    cin>>n1>>n2;

    cout<<"Enter the elements for nums1:\n";
    int ele1;
    for(int i=0;i<n1;i++){
        cin>>ele1;
        nums1.push_back(ele1);
    }

    cout<<"Enter the elements for nums2:\n";
    int ele2;
    for(int i=0;i<n2;i++){
        cin>>ele2;
        nums2.push_back(ele2);
    }
    vector<int>result=nextGreaterElement(nums1,nums2);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}