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
    ll a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a+2),t(b+2), xl(q);
    s[0]=-1e18;
    t[0]=-1e18;
    for(int i = 0; i < a; i++)
    {
        cin>>s[i+1];
    }
    for(int i = 0; i < b; i++)
    {
        cin>>t[i+1];
    }
    s[a+1]=1e18;
    t[b+1]=1e18;
    for(int i = 0; i < q; i++)
    {
        cin>>xl[i];
    }
    for(int i = 0; i < q; i++)
    {
        ll x = xl[i];
        ll s1, s2, t1, t2, ans=1e18;
        s1 = s[lower_bound(all(s),x)-s.begin()-1];
        s2 = s[lower_bound(all(s),x)-s.begin()];
        t1 = t[lower_bound(all(t),x)-t.begin()-1];
        t2 = t[lower_bound(all(t),x)-t.begin()];
        //cout<<s1<<"\t"<<s2<<"\t"<<t1<<"\t"<<t2<<endl;
        ans = min(ans, abs(x-s1)+abs(s1-t1));
        ans = min(ans, abs(x-t1)+abs(s1-t1));

        ans = min(ans, abs(x-s1)+abs(s1-t2));
        ans = min(ans, abs(x-t2)+abs(s1-t2));

        ans = min(ans, abs(x-s2)+abs(s2-t1));
        ans = min(ans, abs(x-t1)+abs(s2-t1));

        ans = min(ans, abs(x-s2)+abs(s2-t2));
        ans = min(ans, abs(x-t2)+abs(s2-t2));

        cout<<ans<<endl;
    }
    
    
    return 0;
}