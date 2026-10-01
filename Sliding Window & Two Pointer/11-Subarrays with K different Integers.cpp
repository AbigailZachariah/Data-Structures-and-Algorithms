#include <bits/stdc++.h>
using namespace std;

int helper (vector<int>nums,int k){
    int l=0,r=0,cnt=0;
    map<int,int>mpp;
    int n=nums.size();

    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums,k)-helper(nums,k-1);
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

    cout<<subarraysWithKDistinct(nums,k);
    return 0;
}