#include<bits/stdc++.h>
using namespace std;

int numOfDay(vector<int>&weights,int cap){
    int days=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+load>cap){
            days+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int n=weights.size();
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int numberOfDays=numOfDay(weights,mid);
        if(numberOfDays<=days){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int main()
{
    vector<int> nums;
    int num;
    cout << "Enter the number of elements:";
    cin >> num;
    int days;

    cout << "Enter the elements:";
    cout << endl;
    int ele;
    for (int i = 0; i < num; i++)
    {
        cin >> ele;
        nums.push_back(ele);
    }
    cout<<"Enter the number of days:";
    cin>>days;

    cout << "Least Weight Capacity:" << shipWithinDays(nums,days);
    return 0;
}