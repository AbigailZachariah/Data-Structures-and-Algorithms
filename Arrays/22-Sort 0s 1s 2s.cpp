# include <bits/stdc++.h>
using namespace std;

void sortingnos(vector<int>&arr){
    int n=arr.size();
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    vector<int>arr;

    int num; 
    cout<<"Enter the number of elements in the array:";
    cin>>num;

    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<num;i++){
        cin>>ele;
        arr.push_back(ele);
    }  
    sortingnos(arr);

    for(int it:arr){
        cout<<it<<" ";
    }
    return 0;
}