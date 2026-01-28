#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>nums,int x){
    //smalest index such that nums[i]>=x
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>nums,int x){
    //smalest index such that nums[i]>x
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr;
    int num;
    int x;
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
    cout<<"Enter value for which lower and upper bound  needs to be found for:";
    cin>>x;

    cout << "lower bound:"<<lowerBound(arr,x)<<" upper bound:"<<upperBound(arr,x);
    return 0;
}