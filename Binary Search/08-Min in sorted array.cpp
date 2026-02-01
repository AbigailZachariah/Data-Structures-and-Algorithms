#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]){
            ans=min(ans,nums[low]);
            break;
            }
        if(nums[low]<=nums[mid]){
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    
    cout<<"Minimum:"<<findMin(arr);    
    return 0;
}