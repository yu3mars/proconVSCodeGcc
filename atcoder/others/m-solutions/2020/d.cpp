#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll money=1000;
    ll stock=0;
    for (int i = 0; i < n; i++)
    {
        money+=stock*a[i];
        stock=0;
        if(i==n-1) break;
        if(a[i]<a[i+1])
        {
            stock=money/a[i];
            money%=a[i];
        }
    }
    cout<<money<<endl;
    
    return 0;
}