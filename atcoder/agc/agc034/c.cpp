#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tllll = tuple<ll,ll,ll,ll>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> b(n),l(n),u(n);
    for (int i = 0; i < n; i++)
    {
        cin>>b[i]>>l[i]>>u[i];
    }

    ll ans=0;
    ll aokisum=0;
    for (int i = 0; i < n; i++)
    {
        aokisum+=b[i]*l[i];
    }

    vector<tllll> tup(n);
    for (int i = 0; i < n; i++)
    {
        ll tyoukaMax = (x-b[i])*u[i];
        tup[i]=make_tuple(tyoukaMax, b[i],l[i],u[i]);
    }
    sort(all(tup));
    reverse(all(tup));
    ll takasum=0;
    ll testcnt=0;
    while (takasum < aokisum)
    {
        ll tyouka = get<0>(tup[testcnt]);
        ll bi= get<1>(tup[testcnt]);
        ll li= get<2>(tup[testcnt]);
        ll ui= get<3>(tup[testcnt]);
        if(takasum + tyouka +bi*li <= aokisum)
        {
            ans+=x;
            takasum+=tyouka+bi*ui;
            aokisum += bi*(ui-li);
            testcnt++;

        }
        else break;
    }
    if(takasum<aokisum)
    {
        ll nokori = aokisum-takasum;
        ll mi = 1e15;
        for (int i = testcnt; i < n; i++)
        {
            ll bi= get<1>(tup[i]);
            ll li= get<2>(tup[i]);
            ll ui= get<3>(tup[i]);
            //a>=b
            ll aLarge = (nokori + bi*(li-ui) + ui-1)/ui;
            if(bi<=aLarge && aLarge<=x)
            {
                mi=min(mi,aLarge);
            }

            //a<=b
            ll aSmall = (nokori + li-1)/li;
            if(aSmall>=0 && aSmall<=bi)
            {
                mi=min(mi,aSmall);
            }
            //cout<<aLarge<<" "<<aSmall<<endl;
        }
        ans+=mi;
    }

    cout<<ans<<endl;
    return 0;
}