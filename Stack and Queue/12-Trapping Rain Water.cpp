#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int lMax=0;
    int rMax=0;
    int total=0;

    int l=0;
    int r=height.size()-1;

    while(l<r){
        if(height[l]<=height[r]){
            if(lMax>height[l]){
                total+=lMax-height[l];
            }
            else lMax=height[l];// updating to new lMax
            l++;
        }
        else{
            if(rMax>height[r]){
                total+=rMax-height[r];
            }
            else rMax=height[r];
            r--;
        }
    }
    return total;
}

int main(){
    vector<int>height;

    int n;
    cout<<"Enter the size of the arrays:\n";
    cin>>n;

    cout<<"Enter the height of buildings:\n";
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        height.push_back(ele);
    }
    cout<<"Total:"<<trap(height);
    return 0;
}