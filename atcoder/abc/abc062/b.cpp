#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    string s;
    int h,w;
    cin >> h>>w;
    
    for(int i = 0; i < w+2; i++)
    {
        cout << "#";
    }
    cout << endl;

    
    for(int i = 0; i < h; i++)
    {
        cout << "#";
        cin>> s;
        cout << s;
        cout << "#";
        cout << endl;
    }
    

    for(int i = 0; i < w+2; i++)
    {
        cout << "#";
    }
    cout << endl;

    return 0;
}