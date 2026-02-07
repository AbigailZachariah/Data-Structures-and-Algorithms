#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low + k;
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
    cout<<"Kth positive number:";
    cin>>k;

    cout << "kth number:" << findKthPositive(nums,k);
    return 0;
}