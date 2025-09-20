# include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    int number;
    cout<<"Enter the number of elements:";
    cin>>number;

    int ele;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<number;i++){
        cin>>ele;
        nums.push_back(ele);
    }
    // Left rotate array by one place
    int temp=nums[0]; // Storing the first element in a variable temp
    for(int i=1;i<number;i++){
        nums[i-1]=nums[i];
    }
    nums[number-1]=temp;
    cout<<"The Rotated Array: "<<endl;
    for(int i=0;i<number;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}