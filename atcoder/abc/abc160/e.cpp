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
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<ll> p(a),q(b),r(c);
    for (int i = 0; i < a; i++)
    {
        cin>>p[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin>>q[i];
    }
    for (int i = 0; i < c; i++)
    {
        cin>>r[i];
    }
    

    sort(all(p));
    sort(all(q));
    sort(all(r));
    reverse(all(p));
    reverse(all(q));
    reverse(all(r));
    
    ll pcnt=0,qcnt=0,rcnt=0,ans=0;
    while (pcnt+qcnt+rcnt<x+y)
    {
        if(pcnt>=x)
        {
            if(q[qcnt] <= r[rcnt])
            {
                ans+=r[rcnt];
                rcnt++;
            }
            else
            {
                ans+=q[qcnt];
                qcnt++;
            }
        }
        else if (qcnt>=y)
        {
            if(p[pcnt] <= r[rcnt])
            {
                ans+=r[rcnt];
                rcnt++;
            }
            else
            {
                ans+=p[pcnt];
                pcnt++;
            }
        }
        else
        {
            if(p[pcnt] <= r[rcnt] && q[qcnt] <= r[rcnt])
            {
                ans+=r[rcnt];
                rcnt++;
            }
            else if(p[pcnt] <= q[qcnt] && r[rcnt] <= q[qcnt])
            {
                ans+=q[qcnt];
                qcnt++;
            }
            else
            {
                ans+=p[pcnt];
                pcnt++;
            }
        }
        
    }
    

    cout<<ans<<endl;

    return 0;
}