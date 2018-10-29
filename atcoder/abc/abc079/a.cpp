#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    string s;
    cin >> s;
    if(s.at(1) == s.at(2) && 
        (s.at(0) == s.at(1) || s.at(2)==s.at(3)))
    {
        cout << "Yes"<< endl;
    }
    else 
    {
        cout << "No" << endl;
    }

    return 0;
}