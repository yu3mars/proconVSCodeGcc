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
    vector<ll> a(n),b(n),ooi;
    ll sukunai=0;
    ll ans=-1;
    ll sukunaicnt=0;
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(a[i]<b[i])
        {
            sukunai+=b[i]-a[i];
            sukunaicnt++;
        }
        else if(a[i]>b[i])
        {
            ooi.push_back(a[i]-b[i]);
        }
    }
    sort(all(ooi));
    reverse(all(ooi));
    
    for(int i = 0; i < ooi.size(); i++)
    {
        if(sukunai<=0)
        {
            ans=i+sukunaicnt;
            break;
        }
        sukunai-=ooi[i];
        if(sukunai<=0)
        {
            ans=i+1+sukunaicnt;
            break;
        }
    }
    

    cout<<ans<<endl;
    return 0;
}