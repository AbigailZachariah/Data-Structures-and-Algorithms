#include<bits/stdc++.h>
using namespace std ;

int func(int mid,int N,int M ){
  long long ans=1;
  for(int i=1;i<=N;i++){
    ans=ans*mid;
    //At any point
    if(ans>M) return 2;
  }
  if(ans==M)return 1;
  return 0;
}
int NthRoot(int N, int M) {
    int low=1,high=M;
    while(low<=high){
        int mid=(low+high)/2;
        int nth=func(mid,N,M);
        if(nth==1){
          return mid;
        }
        else if(nth ==0){
          low=mid+1;
        }
        else high=mid-1;
    }
    return -1;
}

int main()
{
    int num;
    int N;
    cout << "Enter the number whose Nth root is to be found:";
    cin >> num;
    cout<<"Enter the value of N:";
    cin>>N;
    
    cout<<"Nth Root:"<<NthRoot(N,num);    
    return 0;
}