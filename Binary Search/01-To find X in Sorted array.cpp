#include <bits/stdc++.h>
using namespace std;

int binaryIndex(vector<int>nums,int n,int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(target>nums[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int BinarySearch(vector<int>&nums,int target){
    return binaryIndex(nums,nums.size(),target);
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
    cout<<"Enter value to be searched:";
    cin>>target;

    cout << "Index of target:"<<BinarySearch(arr,target);
    return 0;
}