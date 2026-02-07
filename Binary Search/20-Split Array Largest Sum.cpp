#include <bits/stdc++.h>
using namespace std;

int cntSubarrays(vector<int>&nums,int maxSumLimit){
    int subarrayCount=1;
    int currentSum=0;
    for(int i=0;i<nums.size();i++){
        if(currentSum+nums[i]<=maxSumLimit){
            currentSum+=nums[i];
        }
        else{
            subarrayCount++;
            currentSum=nums[i];
        }
    }
    return subarrayCount;
}
int splitArr(vector<int>&nums,int m){
    int n=nums.size();

    if(m>n) return -1;

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int Lsum=cntSubarrays(nums,mid);
        if(Lsum>m){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low;
}
int splitArray(vector<int>& nums, int k) {
    return splitArr(nums,k);
}

int main()
{
    vector<int> nums;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;
    int k;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    cout<<"Number of non-empty subarrays:";
    cin>>k;

    cout << "Minimized Largest Sum:" << splitArray(nums,k);
    return 0;
}