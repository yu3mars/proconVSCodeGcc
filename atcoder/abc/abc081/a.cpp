#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int ans=0;
    string s;
    cin >> s;
    
    for(int i = 0; i < 3; i++)
    {
        if(s.at(i)=='1')
        {
            ans++;
        }
    }
    cout << ans << endl;
 
    return 0;
}