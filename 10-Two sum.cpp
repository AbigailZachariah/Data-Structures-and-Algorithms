# include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int val) {
    for (int i=0;i<nums.size();i++){
        for (int j=i+1;j<nums.size();j++){
            if((nums[i]+nums[j])==val){
                return{i,j};
            }
        }
    }
    return{};
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
    int value;
    cout<<"Enter the target value:";
    cin>>value;

    vector<int>R=twoSum(nums,value);
    if(R.empty()){
        cout<<"No match found!";    
    }
    else cout<<R[0]<<" "<<R[1]<<endl;
    return 0;
}
