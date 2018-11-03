#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    ll ans=0;
    string s;
    cin >> s;
    int n = s.length();
    
    for(int bit = 0; bit < (1<< (n-1)); bit++)
    {
        ll tmp = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i==n-1)
            {
                tmp = tmp*10 + s.at(i)-'0';
                ans+=tmp;
                tmp=0;
            }
            else
            {
                if((bit>>i)&1 == 1) // + ari
                {
                    tmp = tmp*10 + s.at(i)-'0';
                    ans+=tmp;
                    tmp=0;
                }
                else
                {
                    tmp = tmp*10 + s.at(i)-'0';
                }
            }
        }
        
    }
    

    cout << ans << endl;
    
    return 0;
}