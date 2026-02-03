#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n)  {
    int low=1;
    int high=n;
    int ans=1;
    while(low<=high){
        long long mid=(low+high)/2;
        long long value=(mid*mid);
        if(value<=n){
            ans=mid;//might be an answer
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    int num;
    cout << "Enter the number whose square root is to be found:";
    cin >> num;
    
    cout<<"Square Root:"<<floorSqrt(num);    
    return 0;
}