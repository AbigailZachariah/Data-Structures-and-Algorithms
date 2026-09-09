#include <bits/stdc++.h>
using namespace std;  

int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    int lSum=0;
    int rSum=0;
    int maxSum=0;
    for(int i=0;i<k;i++){
        lSum+=cardPoints[i];
    }
    maxSum=lSum;

    int rInd=n-1;
    for(int i=k-1;i>=0;i--){
        lSum-=cardPoints[i];
        rSum+=cardPoints[rInd];
        maxSum=max(maxSum,lSum+rSum);
        rInd--;
    }
    return maxSum;
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

    int k;
    cout<<"Enter k:";
    cin>>k;

    cout<<maxScore(nums,k);
    return 0;
}