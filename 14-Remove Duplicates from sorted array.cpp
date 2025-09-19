//This problem takes a sorted array and returns the number of unique elements 
#include <bits/stdc++.h>
using namespace std;

int remove_duplicates(vector<int> arr, int n){    //n is the number of elements in the array
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1; //Returning number of unique elements
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
    int result= remove_duplicates(nums,number);
    cout<<"Number of unique elements" <<result;
    return 0;
}