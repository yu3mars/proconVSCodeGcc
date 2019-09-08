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
    ll n, ans=0;
    cin>>n;
    vector<vector<ll>> a(n);
    vector<ll> cnt(n);
    for (int i = 0; i < n; i++)
    {
        a[i]=vector<ll>(n);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            cin>>a[i][j];
            a[i][j]--;
        }        
    }
    bool changed = true;
    while (changed==true)
    {
        changed=false;
        queue<ll> exe;
        for (ll i = 0; i < n; i++)
        {
            if(cnt[i]>=n-1) continue;
            ll j = a[i][cnt[i]];
            if(a[j][cnt[j]]==i)
            {
                exe.push(i);
            }
        }
        if(exe.size()>0)
        {
            changed=true;
            ans++;
        }
        while (exe.size()>0)
        {
            ll pp = exe.front();
            exe.pop();
            cnt[pp]++;
        }
        
    }
    
    for (ll i = 0; i < n; i++)
    {
        if(cnt[i]!=n-1)
        {
            ans=-1;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}
