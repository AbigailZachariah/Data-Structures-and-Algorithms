#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > powerSet(vector<int>& nums) {
    int n=nums.size();
    int total=1<<n;

    vector<vector<int>>subsequences;

    for(int num=0;num<total;num++){
        vector<int> subseq;
        for(int i=0;i<n;i++){
            if((num & (1<<i))!=0){
                subseq.push_back(nums[i]);
            }
        }
        subsequences.push_back(subseq);
    }
    return subsequences;
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

    vector<vector<int>>result;
    result=powerSet(nums);

    for (auto arr : result) {
        for(int it:arr){
            cout << it<" ";
        }
        cout<<endl;
    }
    cout << endl;
    return 0;
}