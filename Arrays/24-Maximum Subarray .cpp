#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int s = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        s += nums[i];
        if (s > maxi)
        {
            maxi = s;
        }
        if (s < 0)
        {
            s = 0;
        }
    }
    return maxi;
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

    cout << "Subarray with largest sum:" << maxSubArray(arr);
    return 0;
}