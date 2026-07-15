#include<bits/stdc++.h>
using namespace std;

int count_primes(int n){
    int count=0;
    vector<int>primes(n);
    for(int i=2;i<n;i++){
        primes[i]=1;
    }
    for(int i=2;i*i<n;i++){
        if(primes[i]==1){
            for(int j=i*i;j<n;j+=i){
                primes[j]=0;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(primes[i]==1){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    cout<<count_primes(n);
    return 0;
}