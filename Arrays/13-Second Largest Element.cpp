#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int>& nums ,int n) {
    int largest=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]>largest){
            largest=nums[i];
        }

    }
    int second_largest=-1;
    for (int i=0;i<n;i++){
        if(nums[i]>second_largest && nums[i]!=largest){
            second_largest=nums[i];
        }
    }
    if(!second_largest){
        return -1;
    }
    else return second_largest;
}

int main(){
    vector<int> sl;
    int number;
    cout<<"Enter the number of elements:";
    cin>>number;

    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<number;i++){
        cin>>ele;
        sl.push_back(ele);
    }
    int result= secondLargestElement(sl,number);
    cout<<endl<<result;
}