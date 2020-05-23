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
    ll n,k,now=0;
    cin>>n>>k;
    vector<ll> a(n),dist(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i]--;
        dist[i]=-1;
    }
    dist[0]=k;
    
    for (ll i = k-1; i >= 0; i--)
    {
        ll next=a[now];
        if(dist[next]==-1)
        {
            dist[next]=i;
        }
        else
        {
            ll loop=dist[next]-i;
            i%=loop;
            //cout<<"loop "<<loop<<endl;
        }

        /*
        cout<<i<<" "<<now<<" "<<next<<"  ";
        for (int i = 0; i < n; i++)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;
        */
        now=next;
    }
    
    cout<<now+1<<endl;
    
    return 0;
}