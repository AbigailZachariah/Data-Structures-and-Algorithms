#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> nums, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(vector<int> nums, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int first = lowerBound(nums, n, target);
    if (first == n || nums[first] != target)
    {
        return {-1, -1};
    }
    else
    {
        return {first, upperBound(nums, n, target) - 1};
    }
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

    vector<int>result=searchRange(arr,target);
    cout << "First:"<<result[0]<<" Last:"<<result[1];
    return 0;
}