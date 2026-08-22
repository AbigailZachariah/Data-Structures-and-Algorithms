#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int>ans;
    deque<int>dq;

    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k) dq.pop_front();

            
        while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
        dq.push_back(i);

        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int>nums;

    int n;
    cout<<"Enter the size of the arrays:\n";
    cin>>n;

    cout<<"Enter the elements:\n";
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    int K;
    cout<<"Enter the Value of K:";
    cin>>K;

    vector<int>Result =maxSlidingWindow(nums,K);
    for(auto it:Result){
        cout<<it<<" ";
    }

    return 0;
}