#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int h,w,k;
    cin >> h>>w>>k;
    ll mod = 1e9+7;
    ll dp[105][10]; //takasa, bou;
    m0(dp);
    dp[0][0]=1;
    
    for(int hh = 0; hh < h; hh++)
    {
        
        for(int bit = 0; bit < (1<<(w-1)); bit++)
        {
            bool bitok = true;
            
            for(int i = 0; i < w-2; i++)
            {
                if(((bit>>i) & (bit>>(i+1)) & 1) ==1)
                {
                    bitok = false;
                    break;
                }
            }
            if(bitok==false) continue;
            
            for(int bou = 0; bou < w; bou++)
            {
                if((bit>>bou) & 1)
                {
                    dp[hh+1][bou]+=dp[hh][bou+1];
                    dp[hh+1][bou+1]+=dp[hh][bou];
                    dp[hh+1][bou]%=mod;
                    dp[hh+1][bou+1]%=mod;
                    bou++;
                }
                else
                {
                    dp[hh+1][bou]+=dp[hh][bou];
                    dp[hh+1][bou]%=mod;
                }

            }
            
        }
        
    }

    if(w>1)
    {
        cout << dp[h][k-1] << endl;
    }
    else
    {
        cout << 1 << endl;
    }
    return 0;
}