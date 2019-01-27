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
    ll l,n;
    cin >>l>>n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    ll ans=0, now=0,bef=0,aft=n-1;
    while(bef<=aft)
    {
        ll befLen,aftLen;
        if(now < x[bef])
        {
            befLen = x[bef]-now;
        }
        else
        {
            befLen = l - now + x[bef];
        }

        if(now < x[aft])
        {
            aftLen = now + l - x[aft];
        }
        else
        {
            aftLen = now - x[aft];
        }

        if(befLen < aftLen)
        {
            ans+=aftLen;
            now = x[aft];
            aft--;
        }
        else 
        {
            ans+=befLen;
            now = x[bef];
            bef++;
        }

        //debug
        cout<<now<<"\t"<< bef<<"\t"<<aft<<"\t"<<befLen<<"\t"<<aftLen<<"\t"<<ans<<endl;
    }

    cout<<ans<<endl;
    return 0;
}