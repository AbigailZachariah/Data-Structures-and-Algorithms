#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    int cnt = 0;
    int noOfBouquet = 0;

    for (int i = 0; i < bloomDay.size(); i++){
        if (bloomDay[i] <= day){
            cnt++;
        }
        else{
            noOfBouquet += (cnt / k);
            cnt = 0;
        }
    }
    noOfBouquet += (cnt / k);
    return noOfBouquet >= m;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long val = m * 1LL * k * 1LL;
    if (val > n)
        return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++){
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    int low = mini;
    int high = maxi;
    while (low <= high){
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k)){
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
    int m;
    int k;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    cout << "Number of Bouquets:";
    cin >> m;

    cout<<"Adjacent flowers:";
    cin>>k;

    cout << "Minimum number of days:" << minDays(nums, m,k);
    return 0;
}