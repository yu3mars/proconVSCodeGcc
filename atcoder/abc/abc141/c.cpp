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
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(q), cnt(n), ans(n);
    for (int i = 0; i < q; i++)
    {
        cin>>a[i];
        a[i]--;
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = k - (q - cnt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(ans[i]>0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        
    }
    

    return 0;
}