#include<iostream>
using namespace std;

//A prime number is a number that has two factors 1 and itself 
int main() {
	
	int n;
    cout<<"Enter the integer:";
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){              
			cnt++;    //Increasing the count by 1 if the number is divisible
		}
	
	}
	if(cnt==2) cout<<"True";
	else cout<<"False";
    return 0;
}

