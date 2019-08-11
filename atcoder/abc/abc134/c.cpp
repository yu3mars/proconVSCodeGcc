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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll first=0,second=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>=first)
        {
            second = first;
            first = a[i];
        }
        else if(a[i]>=second)
        {
            second = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]==first)
        {
            cout<<second<<endl;
        }
        else cout<<first<<endl;
    }
    
        
    return 0;
}