#include <bits/stdc++.h>
using namespace std;

vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    int n=arr.size();
    vector<int>ans;

    for(int i=0;i<indices.size();i++){
        int ind=indices[i];
        int count=0;
        for(int j=ind+1;j<n;j++){
            if(arr[j]>arr[ind]) count++;
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    vector<int>nums;
    vector<int>queries;

    int n1,n2;
    cout<<"Enter the size of the arrays:\n";
    cin>>n1>>n2;

    cout<<"Enter the elements for nums:\n";
    int ele1;
    for(int i=0;i<n1;i++){
        cin>>ele1;
        nums.push_back(ele1);
    }

    cout<<"Enter the indices:\n";
    int ele2;
    for(int i=0;i<n2;i++){
        cin>>ele2;
        queries.push_back(ele2);
    }
    vector<int>result=count_NGE(nums,queries);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}