#include <bits/stdc++.h>
using namespace std;

int find_even_num(vector<int>& nums){
    int even_num=0;
    for (int i=0;i<nums.size();i++){
        int cnt=0;
        while (nums[i]>0){
            nums[i]/=10;
            cnt++;
        }
        if(cnt%2==0){
            even_num++;
        }
    }
    return even_num;
}

int main(){
    vector<int>nums;
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    
    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }
    int number_even=find_even_num(nums);
    cout<< number_even;
    return 0;
}