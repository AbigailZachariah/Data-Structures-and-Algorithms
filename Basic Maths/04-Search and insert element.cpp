#include<bits/stdc++.h>
using namespace std;

int search_Insert(vector<int>& nums, int target) {
    
    for (int i=0;i<nums.size();i++){
        if(nums[i]==target){
            return i; //index returned
        }
        if(target<nums[0]){
            return 0; // value less than the first value
        }
        if (i<nums.size()-1){
            if(nums[i]<target && target<nums[i+1]){
                return i+1;
            } 
        }
        
        }
}

int main(){
    vector<int>vec;
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cout<<"Enter the element:";
        cin>>ele;
        vec.push_back(ele);
    }
    int target;
    cout<<"Enter the target value:";
    cin>>target;
    int index=search_Insert(vec,target);
    cout<<index;
    return 0;
}