#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &nums, int dist, int k)
{
    int n = nums.size();
    int cntCows = 1;
    int last = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] - last >= dist)
        {
            cntCows++;
            last = nums[i];
        }
        if (cntCows >= k)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int low = 1;
    int high = nums[n - 1] - nums[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(nums, mid, k) == true)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
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
    cout<<"Number of cows:";
    cin>>k;

    cout << "Maximum possible minimum distance:" << aggressiveCows(nums,k);
    return 0;
}