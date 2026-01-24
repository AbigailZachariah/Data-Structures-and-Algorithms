#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr;

    int number; 
    cout<<"Enter the number of elements in the array:";
    cin>>number;

    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<number;i++){
        cin>>ele;
        arr.push_back(ele);
    }  
    
    int cnt=0;
    int maxi=0;
    for(int i=0;i<number;i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else cnt=0;
    }
    cout<<"The maximum number of consecutive ones:"<<maxi;
    return 0;
}