#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>nums,int k){
    int n=nums.size();
    unordered_map<int,int>mpp;
    mpp[0]=1;
    int preSum=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        preSum+=nums[i];
        int remove=preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]++;
    }
    return cnt;
}
int main(){
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
    int k;
    cout<<"Enter the sum:";
    cin>>k;

    cout<<"The number of Subarrays with sum k:"<<subarraySum(arr,k);
    return 0;
}