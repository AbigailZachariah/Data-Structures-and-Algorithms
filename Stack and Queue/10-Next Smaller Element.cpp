#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(const vector<int>& arr) {
        
    vector<int>nse(arr.size());
    stack<int>st;

    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        if(st.empty())nse[i]=-1;
        else nse[i]=st.top();
        st.push(arr[i]);
    }
    return nse;
        
}

int main(){
    vector<int>nums1;

    int n1;
    cout<<"Enter the size of the arrays:\n";
    cin>>n1;

    cout<<"Enter the elements for nums1:\n";
    int ele1;
    for(int i=0;i<n1;i++){
        cin>>ele1;
        nums1.push_back(ele1);
    }

    vector<int>result=nextSmallerElements(nums1);
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}