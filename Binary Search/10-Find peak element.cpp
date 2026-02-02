#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1;
    int high = n - 2;
    while (low <= high){
        int mid = (low + high) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
            return mid;
        }
        else if (nums[mid] > nums[mid - 1])
            low = mid + 1;
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    
    cout<<"Index of peak element:"<<peakElement(nums);    
    return 0;
}