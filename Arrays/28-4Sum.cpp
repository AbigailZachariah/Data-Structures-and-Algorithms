#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>fourSum(vector<int>&nums, int target){
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])continue;

        for(int j=i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1])continue;

            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];

                if(sum==target){
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    k--;

                    while(k<l && nums[k]==nums[k-1])k++;
                    while(k<l && nums[l]==nums[l+1])l--;
                }
                else if(sum<target)k++;
                else l--;
            }
        }
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
    int target;
    cout<<"Enter the target sum:";
    cin>>target;

    vector<vector<int>>ans=fourSum(arr,target);
    if(ans.empty()){
        cout<<"No Quadruplets"<<endl;
    }
    else{
        for(auto row:ans){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<endl;
        }
    }
    return 0;
}