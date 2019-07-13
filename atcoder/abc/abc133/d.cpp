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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    sum/=2;
    ll no1 = sum;
    for (int i = 1; i < n; i+=2)
    {
        no1 -= a[i];
    }
    vector<ll> ans(n);
    ans[0]=no1*2;
    for (int i = 1; i < n; i++)
    {
        no1 = a[i-1]-no1;
        ans[i]=no1*2;
    }
    for (int i = 0; i < n; i++)
    {
        if(i>0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}