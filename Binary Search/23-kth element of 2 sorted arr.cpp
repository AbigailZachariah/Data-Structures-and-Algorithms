#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int k){
    int n1 = a.size();
    int n2 = b.size();
    if (n2 < n1) return kthElement(b, a, k);

    int low = max(0, k - n2);
    int high = min(k, n1);

    int left = k;
    int n = n1 + n2;

    while (low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];

        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0;
}

int main()
{
    // vector 1
    vector<int> nums1;
    int num1;
    cout << "Enter the number of elements:";
    cin >> num1;

    cout << "Enter the elements:";
    cout << endl;
    int ele1;
    for (int i = 0; i < num1; i++)
    {
        cin >> ele1;
        nums1.push_back(ele1);
    }

    // vector 2
    vector<int> nums2;
    int num2;
    cout << "Enter the number of elements:";
    cin >> num2;

    cout << "Enter the elements:";
    cout << endl;
    int ele2;
    for (int i = 0; i < num2; i++)
    {
        cin >> ele2;
        nums2.push_back(ele2);
    }
    int k;
    cout<<"Enter the value of k:";
    cin >>k;

    cout << "kth Element:" << kthElement(nums1, nums2,k);
    return 0;
}