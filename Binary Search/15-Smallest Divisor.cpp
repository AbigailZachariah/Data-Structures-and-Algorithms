#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int> &nums){
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++){
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}
int sumOfDiv(vector<int> &nums, int limit){
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++){
        sum = sum + ceil((double)nums[i] / (double)limit);
    }
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold){
    int n = nums.size();
    int low = 1;

    int high = maximum(nums);
    while (low <= high){
        int mid = (low + high) / 2;
        if ((sumOfDiv(nums, mid)) <= threshold){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> nums;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;
    int threshold;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    cout<<"Enter the threshold value:";
    cin>>threshold;

    cout << "Smallest Divisor:" << smallestDivisor(nums,threshold);
    return 0;
}