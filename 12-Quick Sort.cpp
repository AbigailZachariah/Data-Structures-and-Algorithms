#include <bits/stdc++.h> 
using namespace std;

int partition_index(vector<int>&arr,int low,int high){
    int pivot=arr[low]; //First element assigned as pivot

    //Creating pointers
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void q_s(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex=partition_index(arr,low,high);
        q_s(arr,low,pIndex-1);
        q_s(arr,pIndex+1,high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    q_s(arr,0,arr.size()-1);
    return arr;
}

//main program
int main(){
    vector<int>nums;
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    
    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>ele;
        nums.push_back(ele);
    }

    vector<int> Sorted_array=quickSort(nums);

    for (auto it:Sorted_array){
        cout<<it<<" ";
    }
    return 0;
}
