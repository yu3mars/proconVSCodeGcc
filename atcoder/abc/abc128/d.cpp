#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main(){
    ll ans=0;
    ll n,k;
    cin>>n>>k;
    vector<int> v(n),vr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
        vr[i]=v[i];
    }
    reverse(all(vr));
    ll dpl[55][105], dpr[55][105];
    for (int i = 0; i < 55; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            dpl[i][j]=LONG_MIN/3;
            dpr[i][j]=LONG_MIN/3;
        }
    }
    dpl[0][0]=0;
    dpr[0][0]=0;
    
    for (int i = 0; i < n; i++)
    {
        dpl[i+1][i+1]=dpl[i][i]+v[i];
        dpr[i+1][i+1]=dpr[i][i]+vr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        vector<ll> pql,pqr;
        for (int j = 0; j < i; j++)
        {
            pql.push_back(v[j]);
            pqr.push_back(vr[j]);
        }
        sort(all(pql));
        sort(all(pqr));
        for (int j = 0; j < i; j++)
        {
            dpl[i][i+j+1]=max(dpl[i][i+j+1], dpl[i][i+j]-pql[j]);
            dpr[i][i+j+1]=max(dpr[i][i+j+1], dpr[i][i+j]-pqr[j]);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dpl[i][j+1]=max(dpl[i][j], dpl[i][j+1]);
            dpr[i][j+1]=max(dpr[i][j], dpr[i][j+1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dpl[i+1][j]=max(dpl[i][j], dpl[i+1][j]);
            dpr[i+1][j]=max(dpr[i][j], dpr[i+1][j]);
        }
    }
    
    for (ll nl = 0; nl <= n; nl++)
    {
        for (ll kl = 0; kl <= k; kl++)
        {
            ll nr=n-nl;
            ll kr=k-kl;
            ll tmp = dpl[nl][kl]+dpr[nr][kr];
            ans=max(ans,tmp);
        }
        
    }
    

    cout<<ans<<endl;
    return 0;
}