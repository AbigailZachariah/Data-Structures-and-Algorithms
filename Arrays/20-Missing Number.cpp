#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int s = 0;
    for (int i = 0; i < n; i++) // finding the sum of all existing elements
    {
        s += nums[i];
    }
    return (sum - s);
}
int main()
{
    vector<int>arr={3,0,1};
    cout<<"The missing element is:"<<missingNumber(arr);
    return 0;
}