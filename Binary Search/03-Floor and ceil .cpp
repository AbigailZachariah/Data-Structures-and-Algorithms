#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= x)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int ceil(vector<int> nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= x)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> getFloorAndCeil(vector<int> nums, int x)
{
    vector<int> ans;
    int fl = floor(nums, x);
    int cl = ceil(nums, x);
    ans.push_back(fl);
    ans.push_back(cl);
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
    cout<<"Enter value for which floor and ceil needs to be found for:";
    cin>>x;

    vector<int>result=getFloorAndCeil(arr,x);
    cout << "Floor and ceil:"<<result[0]<<" "<<result[1];
    return 0;
}