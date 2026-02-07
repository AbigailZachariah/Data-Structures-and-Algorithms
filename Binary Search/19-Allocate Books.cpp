#include <bits/stdc++.h>
using namespace std;

int cntStudent(vector<int>&nums,int pages){
    int n=nums.size();
    int student=1;
    int pagesStudent=0;
    for(int i=0;i<n;i++){
        if(pagesStudent+nums[i]<=pages){
            pagesStudent+=nums[i];
        }
        else{
            student++;
            pagesStudent=nums[i];
        }
    }
    return student;
}
int findPages(vector<int> &nums, int m)  {
    int n=nums.size();
    if(m>n)return -1;

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int Students=cntStudent(nums,mid);
        if(Students>m){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low;
}

int main()
{
    vector<int> nums;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;
    int m;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    cout<<"Number of Students:";
    cin>>m;

    cout << "Maximum number of pages:" << findPages(nums,m);
    return 0;
}