#include <bits/stdc++.h>
using namespace std;

void subSet(int ind,int sum,vector<int>&arr,vector<int>&sumSubset){
    if(ind==arr.size()){
        sumSubset.push_back(sum);
        return;
    }

    subSet(ind+1,sum+arr[ind],arr,sumSubset);

    subSet(ind+1,sum,arr,sumSubset);

}

vector<int> subsetSums(vector<int>& nums) {
    vector<int>sumSubset;
    subSet(0,0,nums,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;
}

int main() {

    int n;
    cout<<"Enter the number of elements:";
    cin>>n;

    vector<int> nums;

    int ele;
    cout<<"Enter the elements:";

    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    vector<int>result=subsetSums(nums);

    for(auto it:result){
        cout<<it<<" ";
    }

    return 0;
}