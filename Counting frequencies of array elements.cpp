#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
       
        map<int,int>mpp;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<vector<int>>result;
        
        for (auto it:mpp){
            result.push_back({it.first,it.second});
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int>nums;
    int n;
    cout<<"Enter the number element: ";
    cin>>n;
    for (int i=0;i<n;i++){
        int ele;
        cout<<"Enter the element: ";
        cin>>ele;
        nums.push_back(ele);
    }
    vector<vector<int>> R=sol.countFrequencies(nums);
    cout<<'[';
    for (auto it:R){
        cout<<"["<<it[0]<<","<<it[1]<<"]";
    }
    cout<<"]";
    return 0;
}