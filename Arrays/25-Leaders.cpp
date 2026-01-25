#include <bits/stdc++.h>
using namespace std;

vector<int>leaders(vector<int>nums){
    vector<int>ans;
    int n=nums.size();
    int maxi=INT_MIN;

    for(int i=n-1;i>0;i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
        }
        maxi=max(maxi,nums[i]);
    }
    return ans;
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

    vector<int>result =leaders(arr);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}