#include <bits/stdc++.h>
using namespace std;

void merge_arrays(vector<int> &nums,int low,int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);  
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right ++;
        }
    }
    // One of the sub-arrays will get exhausted
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right ++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
}

void ms(vector<int> &nums,int low,int high){
    if (low==high) return; // The array has a single element
    int mid=(low+high)/2;
    ms(nums,low,mid);
    ms(nums,mid+1,high);
    merge_arrays(nums,low,mid,high); 
}

vector<int> mergeSort(vector<int>& nums) {
    ms(nums,0,nums.size()-1);
    return nums;
}

//main program
int main(){
    vector<int>arr;
    int num;
    cout<<"Enter the number of elements:";
    cin>>num;
    
    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<num;i++){
        cin>>ele;
        arr.push_back(ele);
    }

    vector<int> Sorted_array=mergeSort(arr);

    for (auto it:Sorted_array){
        cout<<it<<" ";
    }
    return 0;
}
