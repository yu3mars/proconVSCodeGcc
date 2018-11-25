#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    string a,b;
    cin >> a >> b;
    
    int n = stoi(a+b);
    bool ok = false;
    
    for(int i = 1; i*1 <= n; i++)
    {
        if(i*i==n)
        {
            ok = true;
            break;
        }
    }
    if(ok)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}