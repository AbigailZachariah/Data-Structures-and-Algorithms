#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num){
    int ind = -1;

    for (int i = num.size() - 1; i >= 0; i--){
        if ((num[i] - '0') % 2 == 1){
            ind = i;
            break;
        }
    }
    int j = 0;
    while (j <= ind && num[j] == '0') j++;

    return num.substr(j, ind - j + 1);
}

int main()
{
    string str;
    cout << "Enter a string:";
    getline(cin, str);

    cout << largestOddNumber(str);
    return 0;
}