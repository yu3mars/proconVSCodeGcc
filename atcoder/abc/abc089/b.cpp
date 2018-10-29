#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n;
    bool four = false;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if(c=='Y') four = true;
    }
    

    if(four)
    {
        cout << "Four"<< endl;
    }
    else 
    {
        cout << "Three" << endl;
    }

    return 0;
}