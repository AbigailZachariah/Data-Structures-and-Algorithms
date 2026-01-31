# include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
    int n=nums.size();
    int low=0;
    int high =n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return true;
        }
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }
            else low=mid+1;
        }
        else{
            if(nums[mid]<=target && target<=nums[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return false; 
}   
int main()
{
    vector<int> arr;
    int num;
    int target;
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
    cout<<"Enter the target value:";
    cin>>target;
    
    bool result=search(arr,target);
    if(result){
        cout<<"Element exists.";
    }
    else{
        cout<<"Element does not exist.";
    }
    
    return 0;
}