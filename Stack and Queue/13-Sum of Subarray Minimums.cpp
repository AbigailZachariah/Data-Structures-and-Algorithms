#include <bits/stdc++.h>
using namespace std;

vector<int>findNSE(vector<int>arr){
    int n=arr.size();
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}

vector<int>findPSEE(vector<int>arr){
    int n=arr.size();
    vector<int>psee(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        psee[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return psee;
}
int sumSubarrayMins(vector<int>& arr) {
    vector<int>nse=findNSE(arr);
    vector<int>psee=findPSEE(arr);
    int total=0;
    int mod=1e9+7;

    for(int i=0;i<arr.size();i++){
        int left=i-psee[i];
        int right=nse[i]-i;
        /* Count of subarrays*/
        long long freq = left*right*1LL;
            
        // Contribution of current element 
        int val = (freq*arr[i]*1LL) % mod;
            
        // Updating the sum
        total = (total + val) % mod;
    }
    return total;
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
    cout<<"Total:"<<sumSubarrayMins(nums);
    return 0;
}