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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < k; i++)
    {
        vector<ll> imos(n+1);
        bool all0=true;
        bool alln=true;
        for (int j = 0; j < n; j++)
        {
            ll l=max(0LL,j-a[j]);
            ll r=min(n,j+a[j]+1);
            imos[l]++;
            imos[r]--;
        }
        int cnt=0;
        for (int j = 0; j < n; j++)
        {
            cnt+=imos[j];
            a[j]=cnt;
            if(cnt!=0) all0=false;
            if(cnt!=n) alln=false;
        }
        if(all0 || alln)
        {
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout<<a[i];
        if(i==n-1)
        {
            cout<<endl;
        }
        else
        {
            cout<<" ";
        }
        
    }
    
    
    return 0;
}