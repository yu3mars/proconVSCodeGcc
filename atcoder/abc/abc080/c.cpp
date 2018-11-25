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
    int n,ans=-2e9;
    cin>>n;
    int f[105][10],p[105][11];
    m0(f);
    m0(p);

    for(int i = 0; i < n; i++)
    {        
        for(int j = 0; j < 10; j++)
        {
            cin>>f[i][j];
        }        
    }
    
    for(int i = 0; i < n; i++)
    {        
        for(int j = 0; j < 11; j++)
        {
            cin>>p[i][j];
        }        
    }
    
    for(int bit = 1; bit < (1<<10); bit++)
    {
        int cnt[105];
        int tmp=0;
        m0(cnt);
        
        for(int day = 0; day < 10; day++)
        {
            if(((bit>>day)&1)==1)
            {
                for(int store = 0; store < n; store++)
                {
                    if(f[store][day]==1)
                    {
                        cnt[store]++;
                    }
                }
            }
        }
        
        for(int store = 0; store < n; store++)
        {
            tmp+=p[store][cnt[store]];
        }
        ans=max(ans,tmp);
    }
    

    cout<<ans<<endl;

    return 0;
}