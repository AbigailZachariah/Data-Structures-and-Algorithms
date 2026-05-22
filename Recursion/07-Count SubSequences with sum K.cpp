#include <bits/stdc++.h>
using namespace std;

int countwithsumK(int ind,int s,int k,vector<int>&nums,int n){
    if(ind==n){
        if(s==k){
            return 1;
        }
        return 0;
    }
    s+=nums[ind];
    int l=countwithsumK(ind+1,s,k,nums,n);

    s-=nums[ind];
    int r=countwithsumK(ind+1,s,k,nums,n);

    return l+r;
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    int n=nums.size();
    return countwithsumK(0,0,k,nums,n);
}

int main() {

    int n;
    cout<<"Enter the number of elements:";
    cin>>n;

    vector<int> nums;

    int ele;
    cout<<"Enter the elements:";

    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    int k;
    cout<<"Enter the target sum:";
    cin>>k;

    cout<<"The number of sub sequences with sum K: ";
    cout<<countSubsequenceWithTargetSum(nums,k);

    return 0;
}