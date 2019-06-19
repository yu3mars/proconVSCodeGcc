#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tlll = tuple<ll,ll,ll>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

const ll INF = 1e11;
vector<ll> manbgn[200010], manend[200010];

int main()
{
    ll n,q;
    cin>>n>>q;
    vector<tlll> koji(n*2);
    for (int i = 0; i < n; i++)
    {
        ll ss,tt,xx;
        cin>>ss>>tt>>xx;
        koji[i*2]=make_tuple(ss-xx,1,xx);
        koji[i*2+1]=make_tuple(tt-xx,-1,xx);
    }
    vector<ll> ans(q);
    vector<ll> man(q);
    for (int i = 0; i < q; i++)
    {
        cin>>man[i];
        ans[i]=-1;
    }
    sort(all(koji));
    set<ll> se;
    ll nowt = -INF;
    ll kojicnt=0;

    for (ll mani = 0; mani < q; mani++)
    {
        nowt=man[mani];
        while (kojicnt<n*2)
        {
            ll t,b,x;
            t=get<0>(koji[kojicnt]);
            b=get<1>(koji[kojicnt]);
            x=get<2>(koji[kojicnt]);
            if(nowt < t) break;

            kojicnt++;

            if(b==1) se.insert(x);
            else se.erase(x);

        }
        if(se.size()>0)
        {
            ans[mani]=*se.begin();
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        cout<<ans[i]<<endl;
    }
    

    return 0;
}