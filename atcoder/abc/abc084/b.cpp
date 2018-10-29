#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int a,b;
    string s;
    cin >> a >> b >> s;
    bool ok = true;
    
    for(int i = 0; i < a+b+1; i++)
    {
        if(i == a)
        {
            if(s.at(i)!='-') 
            {
                ok = false;
                break;
            }
        }
        else
        {
            if(s.at(i) < '0' || s.at(i) < 9)
            {
                ok = false;
                break;
            }
        }
    }
    
    if(ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}