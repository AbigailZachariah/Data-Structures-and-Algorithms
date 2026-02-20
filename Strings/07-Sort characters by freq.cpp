#include <bits/stdc++.h>
using namespace std;

static bool comparator(pair<int, char> p1, pair<int, char> p2){
    if (p1.first > p2.first)
        return true;
    if (p1.first < p2.first)
        return false;
    return p1.second < p2.second;
}

string frequencySort(string s){
    pair<int, char> freq[128]; // both uppercase and lowercase char
    for (int i = 0; i < 128; i++){
        freq[i] = {0, (char)i};
    }

    for (char ch : s){
        freq[(unsigned char)ch].first++; // using char directly as index
    }

    sort(freq, freq + 128, comparator);

    string ans;
    for (int i = 0; i < 128; i++){
        if (freq[i].first > 0){
            ans.append(freq[i].first, freq[i].second); // adding char as many times as it appears
        }
    }
    return ans;
}

int main(){
    string str;
    cout<<"Enter the string:";
    cin>>str;

    cout<<"Sorting according to frequency:"<<frequencySort(str);
    return 0;
}