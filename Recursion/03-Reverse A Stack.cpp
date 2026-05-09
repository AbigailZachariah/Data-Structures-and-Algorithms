#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&s , int temp){
    if(s.empty()){
        s.push(temp);
        return ;
    }
    int val=s.top();
    s.pop();
    insertAtBottom(s,temp);
    s.push(val);
}

void reverseStack(stack<int> &st) {
    
    if(st.empty()) return;
    int topVal=st.top();

    st.pop();

    reverseStack(st);
    insertAtBottom(st,topVal);
}

int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    reverseStack(s);

    cout << "Reversed stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout <<endl;
    return 0;
}