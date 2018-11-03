#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n,m,ans=0;
    cin >> n >> m;
    bool net[12][12];
    m0(net);
    
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        net[x][y] = true;
        net[y][x] = true;
    }
    
    
    for(int bit = 0; bit < (1<<n); bit++)
    {
        bool ok = true;
        for(int i = 0; i < n; i++)
        {    
            if((bit >> i) & 1)        
            {
                for(int j = i+1; j < n; j++)
                {
                    if((bit>>j)&1)
                    {
                        if(net[i][j] == false)
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok ==false) break;
            }
        }
        if(ok)
        {
            int cnt=0;
            int bittmp=bit;
            
            while(bittmp>0){
                if(bittmp & 1) cnt++;
                bittmp = (bittmp >> 1);
            }
            ans = max(ans,cnt);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}