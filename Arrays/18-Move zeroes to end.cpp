#include <bits/stdc++.h>
using namespace std;

void move_zeroes(vector<int>&arr) {
    int n=arr.size();
    int i=0;
    int j=0;
    for(int k=0;k<n;k++){
        if(arr[k]!=0){
            swap(arr[k],arr[j]);
            j++;
        }
        else i++;
    }
    cout<<"The updated array:  ";
    for(auto it:arr){
        cout<<it<<" ";
    }
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
    
    move_zeroes(nums);
    return 0;
}