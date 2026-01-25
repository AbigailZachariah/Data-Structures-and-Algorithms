#include <bits/stdc++.h>

using namespace std;

int Majority(vector<int>&nums){
    int n=nums.size();
    //Moore's Voting Algorithm

    int cnt=0;
    int ele;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            ele=nums[i];
        }
        else if(nums[i]==ele){
            cnt++;
        }
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(nums[i]==ele){
            cnt1++;
        }
    }
    if(cnt1>n/2){
        return ele;
    }
    return -1;
}
int main(){
    vector<int> arr;
    int num;
    cout<<"Enter the number of elements:";
    cin>>num;

    cout<<"Enter the elements:";
    cout<<endl;
    int ele;
    for(int i=0;i<num;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"The Majority Element appearing more than half of the size of elements:"<<Majority(arr);
    return 0;
}