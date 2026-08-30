#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n=nums.size();
    int l=0,r=0;
    int maxLen=0;
    int zeroes=0;

    while(r<n){
        if(nums[r]==0) zeroes++;
        if(zeroes>k){
            if(nums[l]==0){
                zeroes--;
            }
            l++;
        }
        if(zeroes<=k){
            int len=r-l+1;
            maxLen=max(len,maxLen);
        }
        r++;
    }
    return maxLen;
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

    int k;
    cout<<"Enter k:";
    cin>>k;

    cout<<longestOnes(nums,k);
    return 0;
}