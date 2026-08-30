#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    int n=fruits.size();

    int l=0;
    int r=0;
    int maxLen=0;
    map<int ,int>mpp;

    while(r<n){
        mpp[fruits[r]]++;
        if(mpp.size()>2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
            l++;
        }
        if(mpp.size()<=2){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    vector<int>nums;

    int n;
    cout<<"Enter the size of the arrays:\n";
    cin>>n;

    cout<<"Enter the elements:\n";
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }
    cout<<totalFruit(nums);
    return 0;
}