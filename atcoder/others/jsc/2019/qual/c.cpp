#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll mod = 1e9+7;

int main()
{
    ll n, ans=1, stock=0;
    string s;
    cin>>n>>s;
    for (ll i = 0; i < 2*n; i++)
    {
        if((s[i]=='B' && i%2==0) || (s[i]=='W' && i%2==1) )   //fuyasu
        {
            stock++;
        }
        else //herasu
        {
            ans*=stock;
            ans%=mod;
            stock--;
        }
    }
    if(stock!=0) ans=0;
    for (ll i = 1; i <= n; i++)
    {
        ans*=i;
        ans%=mod;
    }
    

    cout<<ans<<endl;

    return 0;
}