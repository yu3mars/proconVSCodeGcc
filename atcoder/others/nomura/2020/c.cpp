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
    cin>>n;
    vector<ll> a(n+1), maxline(n+1);
    for (int i = 0; i <= n; i++)
    {
        cin>>a[i];
    }

    maxline[n]=a[n];
    for (int i = n-1; i >= 0; i--)
    {
        maxline[i]=maxline[i+1]+a[i];
    }
    
    ll nowline=1;
    ll ans=0;
    bool ok=true;

    for (int i = 0; i <= n; i++)
    {
        //cout<<i<<"\t"<<nowline<<"\t"<<a[i]<<"\t"<<maxline[i]<<endl;

        if(nowline<a[i])
        {
            ok=false;
            break;
        }
        ans+=nowline;
        nowline-=a[i];
        if(i<n)
        {
            nowline=min(nowline*2, maxline[i+1]);

        }
    }
    if(nowline!=0)
    {
        ok=false;
    }

    if(ok)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    
    return 0;
}