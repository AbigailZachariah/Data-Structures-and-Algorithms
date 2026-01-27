#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>nums){
    int n=nums.size();
    int pre=0,suff=0;
    int ans=INT_MIN;

    for(int i=0;i<n;i++){
        if(pre==0)pre=1;
        if(suff==0)suff=1;

        pre*=nums[i];
        suff*=nums[n-i-1];

        ans=max(ans,max(pre,suff));
    }
    return ans;
}
int main()
{
    vector<int> arr;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    cout << "Maximum Product Sum:"<<maxProduct(arr);
    return 0;
}