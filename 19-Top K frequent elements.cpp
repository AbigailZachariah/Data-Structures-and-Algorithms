#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    for (int i = 0; i < k; i++)
    { // top frequent elements
        int cnt = 0;
        int ele = 0;
        for (auto it : mpp)
        {
            if (it.second > cnt)
            {
                cnt = it.second;
                ele = it.first;
            }
        }
        ans.push_back(ele);
        mpp.erase(ele); // removing so the next ele can be found
    }
    return ans;
}

int main(){
    vector<int>arr;
    int k;
    cout<<"Enter k most frequent elements:";
    cin>>k;

    int number; 
    cout<<"Enter the number of elements in the array:";
    cin>>number;

    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<number;i++){
        cin>>ele;
        arr.push_back(ele);
    }  
    vector<int>result=topKFrequent(arr,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
