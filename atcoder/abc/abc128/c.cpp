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
    int ans=0;
    int n,m;
    cin>>n>>m;
    bool b[10][10];
    m0(b);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin>>k;
        for (int j = 0; j < k; j++)
        {
            int ss;
            cin>>ss;
            b[i][ss-1]=true;
        }
    }
    int p[10];
    for (int i = 0; i < m; i++)
    {
        cin>>p[i];
    }
    

    for (int bit = 0; bit < (1<<n); bit++)
    {
        bool ok = true;
        for (int denkyu = 0; denkyu < m; denkyu++)
        {
            int cnt=0;

            for (int swi = 0; swi < n; swi++)
            {
                if(b[denkyu][swi] && (bit & (1<<swi)) >0) cnt++;
            }
            

            if(cnt%2==p[denkyu]) continue;
            else {
                ok=false;
                break;
            }
        }
        
        if(ok) ans++;
    }
    

    cout<<ans<<endl;
    
    return 0;
}