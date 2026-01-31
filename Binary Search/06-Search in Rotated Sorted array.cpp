#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[low] <= nums[mid]){
            if (nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if (nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
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
    
    int index=search(arr,target);
    if(index!=-1){
        cout << "Index of Element:"<<index;
    }
    else{
        cout<<"Element does not exists";
    }
    
    return 0;
}