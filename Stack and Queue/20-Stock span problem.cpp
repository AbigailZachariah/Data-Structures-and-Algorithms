#include <bits/stdc++.h>
using namespace std;

vector <int> stockSpan(vector<int> arr, int n) {
    vector <int>result;
    int ind=-1;
    stack<pair<int,int>>st;
    
    for(int i=0;i<n;i++){
        ind=ind+1;
        int price=arr[i];
    
        while(!st.empty() && st.top().first<=price) st.pop(); //finding pge

            int ans=ind-(st.empty()? -1: st.top().second);
            st.push({price,ind});
            
            result.push_back(ans);
    }
    return result;
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

    vector<int>Result =stockSpan(nums,n);
    for(auto it:Result){
        cout<<it<<" ";
    }

    return 0;
}