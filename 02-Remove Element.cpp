#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0; //The number of the elements not equal to val
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k+=1;
            }
        } 
        return k;
    }
};
int main(){
    Solution sol; //Object creation
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
    int val;
    cout<<"Enter the value:";
    cin>>val;
    int result=sol.removeElement(nums,val);
    cout<<"The number of elements which are not equal to val:"<<result;
    return 0;
}