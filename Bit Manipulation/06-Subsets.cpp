#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>>ans;
    int subset=1<<n;

    for(int i=0;i<subset;i++){
        vector<int>list;
        for(int j=0;j<n;j++){
            //Checking if set or not
            if(i & (1<<j)){
                list.push_back(nums[j]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main(){
    vector<int>nums;
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    
    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }


    vector<vector<int>>result=subsets(nums);
    
    for(vector res:result){
        for(auto it:res){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}