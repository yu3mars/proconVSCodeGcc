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
    vector<bool> v(n);
    for (int i = 0; i < k; i++)
    {
        int d;
        cin>>d;
        for (int j = 0; j < d; j++)
        {
            int a;
            cin>>a;
            a--;
            v[a]=true;
        }
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(v[i]==false) 
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}