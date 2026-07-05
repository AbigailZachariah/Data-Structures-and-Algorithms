#include<bits/stdc++.h>
using namespace std;

int range (int N){
    if(N%4==1) return 1;
    else if (N%4==2) return N+1;
    else if (N%4==3) return 0;
    else return N;
}

int findRangeXOR(int L,int R){
	return range(L-1)^range(R);
}

int main(){
    int L ,R;
    cin>>L>>R;

    cout<<findRangeXOR(L,R);
    return 0;
}