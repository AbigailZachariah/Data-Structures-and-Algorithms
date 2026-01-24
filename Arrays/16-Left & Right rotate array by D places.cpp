#include <bits/stdc++.h>
using namespace std;

void LeftRotate(vector<int>&nums,int d){
    d=d%nums.size();
    reverse(nums.begin(),nums.begin()+d);
    reverse(nums.begin()+d,nums.end());
    reverse(nums.begin(),nums.end());
}
void RightRotate(vector<int>&nums,int d){
    d=d%nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+d);
    reverse(nums.begin()+d,nums.end());
}
int main(){
    int d;
    cout<<"Enter the number of places to be rotated: ";
    cin>>d;

    vector<int>nums1;
    int n1;
    cout<<"Enter the number of elements:";
    cin>>n1;
    
    int el;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n1;i++){
        cin>>el;
        nums1.push_back(el);
    }
    LeftRotate(nums1,d); //Calling the LeftRotate function 
    
    vector<int>nums2;
    int n2;
    cout<<"Enter the number of elements:";
    cin>>n2;
    
    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n2;i++){
        cin>>ele;
        nums2.push_back(ele);
    }
    RightRotate(nums2,d); //Calling the RightRotate function 

    //Printing the array
    cout<<"Left Rotated array:"<<endl;
    for(auto it:nums1){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"Right Rotated array:"<<endl;
    for(auto it:nums2){
        cout<<it<<" ";
    }
    return 0;
}