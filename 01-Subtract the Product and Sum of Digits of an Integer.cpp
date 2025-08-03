#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int pdt=1;
        int s=0;
        while(n>0){
            int r=n%10;
            pdt=pdt*r;
            s=s+r;
            n=n/10; 
        }
       
        return(pdt-s);
    }
};
int main(){
    int n;
    cin>>n;
    Solution sol;
    int result=sol.subtractProductAndSum(n);
    cout<<"Result="<<result;
    return 0;
}