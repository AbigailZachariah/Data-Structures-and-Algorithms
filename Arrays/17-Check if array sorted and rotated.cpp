#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& nums) {
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]>nums[(i+1)%n]){
            cnt++;
        }
    }
    if(cnt>1){
        return 0; //not sorted not rotated
    }
        return 1;
}       
    
int main(){
    vector<int> nums;
    int number;
    cout<<"Enter the number of elements:";
    cin>>number;

    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<number;i++){
        cin>>ele;
        nums.push_back(ele);
    }
    
    cout<< endl<< check(nums);
    return 0;
}