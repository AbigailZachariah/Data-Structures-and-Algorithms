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

long long sumSubarrayMins(vector<int>& arr) {
    vector<int>nse=findNSE(arr);
    vector<int>psee=findPSEE(arr);
    long long total=0;

    for(int i=0;i<arr.size();i++){
        int left=i-psee[i];
        int right=nse[i]-i;
        /* Count of subarrays*/
        long long freq = left*right*1LL;
            
        // Contribution of current element 
        long long val = (freq*arr[i]*1LL);
            
        // Updating the sum
        total = (total + val);
    }
    return total;
}

vector<int> findNGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        int currEle = arr[i];
        while(!st.empty() && arr[st.top()] <= currEle){
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}

vector<int> findPGEE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=0; i < n; i++) {
        int currEle = arr[i];
            
        while(!st.empty() && arr[st.top()] < currEle){
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}

long long sumSubarrayMaxs(vector<int> &arr) {
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);
    int n = arr.size();

    long long sum = 0;
    for(int i=0; i < n; i++) {
        int left = i - pgee[i];
        int right = nge[i] - i;
            
        long long freq = left*right*1LL;
        long long val = (freq*arr[i]*1LL);
        sum = (sum+ val);
    }
    return sum;
}

long long subArrayRanges(vector<int>& nums) {
    return ( sumSubarrayMaxs(nums) - sumSubarrayMins(nums) );
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
    cout<<"Total:"<<subArrayRanges(nums);
    return 0;
}