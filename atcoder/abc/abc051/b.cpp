#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int k,s,ans=0;
    cin >> k>>s;
    
    for(int x = 0; x <= k; x++)
    {
        
        for(int y = 0; y <= k; y++)
        {
            int z = s - x - y;
            if(0<=z && z<=k) ans++;
        }        
    }
    cout << ans << endl;
    
    return 0;
}