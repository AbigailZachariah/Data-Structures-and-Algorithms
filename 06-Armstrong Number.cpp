#include <bits/stdc++.h>
using namespace std;
/*Armstrong number is a number that is equal to the sum of its
 digits each raised to the power of the number of digits*/
bool Check_armstrong(int n){
    int temp=n; // Temporary variable to check if the number is armstrong
    int x=n;    // Temporary variable to find the number of digits
    int arms=0;
    int digits=0;
    while(x>0){
        x/=10;
        digits++;
    }
    while(n>0){
        int r=n%10;
        arms=arms+pow(r,digits);
        n/=10;
    }
    if(arms==temp) return true;
    else return false;
}
int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    bool result=Check_armstrong(num);
    
    if (result==true) cout<<"IT IS ARMSTRONG";
    else cout<<"NOT ARMSTRONG";
    return 0;
}
