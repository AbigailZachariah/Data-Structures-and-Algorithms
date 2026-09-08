#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int goal){
    if(goal<0)return 0; //goal-1 ==>goal =0 ==> 0-1=-1

    int l=0;
    int r=0;
    int cnt=0;
    int sum=0;

    while(r<nums.size()){
        sum+=nums[r]%2; // to add 1 and 0
        while(sum>goal){
            sum-=nums[l]%2;
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return (helper(nums,k))-(helper(nums,k-1));
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

    cout<<numberOfSubarrays(nums,k);
    return 0;
}