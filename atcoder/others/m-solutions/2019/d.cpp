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

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n-1),b(n-1);
    for (int i = 0; i < n-1; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
    {
        cin>>c[i];
    }
    sort(all(c));
    reverse(all(c));

    

    vector<ll> cnt(n);
    for (int i = 0; i < n-1; i++)
    {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    vector<ll> g[n];
    for (int i = 0; i < n-1; i++)
    {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    bool used[n];
    m0(used);
    ll ma = 0;
    ll su=0;
    for (int i = 0; i < n; i++)
    {
        if(cnt[ma]<cnt[i]) ma=i;        
    }
    ll cmax=0;
    for (int i = 0; i < n; i++)
    {
        su+=c[i];
        cmax=max(cmax,c[i]);
    }
    su-=cmax;

    vector<ll> ansls(n);
    ll pqcnt=0;
    pll pma = make_pair(-cnt[ma],ma);
    priority_queue<pll> pq;
    pq.push(pma);
    used[ma] = true;

    while(pq.size()>0)
    {
        pll now = pq.top();
        pq.pop();
        ansls[now.second]=c[pqcnt];
        //cout<<now.second<<" "<<pqcnt <<" "<<c[pqcnt]<<endl;
        pqcnt++;

        for (int i = 0; i < g[now.second].size(); i++)
        {
            ll next = g[now.second][i];
            if(used[next]) continue;
            used[next] = true;
            pq.push(make_pair(-cnt[next],next));
        }
    }

    cout<<su<<endl;
    for (int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<ansls[i];
    }
    cout<<endl;

    return 0;
}