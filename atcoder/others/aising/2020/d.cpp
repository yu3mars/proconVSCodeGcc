#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    ll n;
    string s;
    cin>>n>>s;

    int cntPlane=0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1')
        {
            cntPlane++;
        }
    }
    
    for (int bitrev = 0; bitrev < n; bitrev++)
    {
        int ans=0;
        bool b=true;

        int sum=0;

        for (int i = 0; i < n; i++)
        {
            if(i==bitrev)
            {
                if(s[i]=='0') sum++;
            }
            else
            {
                if(s[i]=='1') sum++;
            }

            
        }
        
        
        
    }
    
    
    return 0;
}