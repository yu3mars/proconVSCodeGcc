#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    ll n;
    cin>>n;
    ll keta =0;
    ll tmp=n;
    ll ans=0;
    for (int i = 0; i < 7; i++)
    {
        if(n/((ll)pow(10,i))>0) keta=i+1;
    }

    if(keta%2==1)
    {
        ans+=n-pow(10,keta-1)+1;
    }
    for (int i = 1; i < keta; i+=2)
    {
        ans+=pow(10,i)-pow(10,i-1);
    }
    cout<<ans<<endl;

    return 0;
}