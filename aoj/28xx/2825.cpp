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
    for(;;)
    {
        int n,m;
        cin>>n>>m;
        if(n==0) break;
        ll mi[10010],ma[10010];
        
        for(int i = 0; i < 10010; i++)
        {
            mi[i]=0;
            ma[i]=0;
        }
        
        for(int mm = 0; mm < m; mm++)
        {
            ll s;
            int k;
            cin>>s>>k;
            
            for(int kk = 0; kk < k; kk++)
            {
                int c;
                cin>>c;
                c--;
                ma[c]+=s;
                if(k==1) mi[c]+=s;
            }
        }
        
        int smin[2]={0,0},smax[2]={0,0};
        for(int i = 0; i < n; i++)
        {
            if(ma[i]>=ma[smax[0]])
            {
                smax[1]=smax[0];
                smax[0]=i;
            }
            else if(ma[i]>=ma[smax[1]])
            {
                smax[1]=i;
            }
            if(mi[i]<=mi[smin[0]])
            {
                smin[1]=smin[0];
                smin[0]=i;
            }
            else if(mi[i]<=mi[smin[1]])
            {
                smin[1]=i;
            }
        }
        ll ans=-1;
        if(smax[0]!=smin[0])
        {
            ans =ma[smax[0]]-mi[smin[0]]+1;
        }
        else
        {
            ans=max(ma[smax[0]]-mi[smin[1]]+1,
            ma[smax[1]]-mi[smin[0]]+1);
        }
        cout<<ans<<endl;
    }

    return 0;
}