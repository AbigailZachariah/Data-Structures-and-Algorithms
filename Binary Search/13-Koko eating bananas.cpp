#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int>&piles){
    int maxi;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}

long long totalHours(vector<int>&piles,int hourly){
    long long totalHrs=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        totalHrs+=ceil((double)piles[i]/(double)hourly);
    }
    return totalHrs;
}

int minRateToEat(vector<int>piles,int h){
    int n=piles.size();
    int low=1;
    int high=findMax(piles);
    while(low<=high){
        int mid=(low+high)/2;
        long long totalHrs=totalHours(piles,mid);
        if(totalHrs<=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main()
{
    vector<int> nums;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;
    int h;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    cout<<"Number of hours Koko gets:";
    cin>>h;
    
    cout<<"Rate at which Koko has to eat bananas:"<<minRateToEat(nums,h);    
    return 0;
}