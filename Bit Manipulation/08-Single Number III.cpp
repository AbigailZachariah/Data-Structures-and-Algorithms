#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> &nums){
    int n = nums.size();
    long xorr = 0;
    for (int i = 0; i < n; i++){
        xorr = xorr ^ nums[i];
    }
    int rightmost = (xorr & xorr - 1) ^ xorr;

    int b1 = 0;
    int b2 = 0;

    for (int i = 0; i < n; i++){
        if (nums[i] & rightmost){
            b1 = b1 ^ nums[i];
        }
        else
            b2 = b2 ^ nums[i];
    }
    return {b1, b2};
}

int main(){
    vector<int>nums;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int number;
        cout<<"Enter the elment: ";
        cin>>number;
        nums.push_back(number);
    }
    
    vector <int> result=singleNumber(nums);
    for(int it:result){
        cout<<it<<" ";
    }
    return 0;
}
