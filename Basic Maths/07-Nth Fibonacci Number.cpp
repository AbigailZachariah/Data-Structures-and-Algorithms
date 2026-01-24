# include <bits/stdc++.h>
using namespace std;

//To return the nth term in Fibonacci series using recursion
int fib(int num){
    if(num<=1) return num;
    return fib(num-1)+fib(num-2);
}

int main(){
    int number;
    cout<<"Enter a number:";
    cin>>number;
    int result=fib(number);
    cout<<"The required term is "<<result;
    return 0;
}