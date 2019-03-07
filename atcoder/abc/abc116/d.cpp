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

int main(){
    ll k,n,ans=0,osum=0, tmp=0;
    cin>>n>>k;
    vector<pll> v(n);   //oishisa, neta
    priority_queue<pll> pqall;
    priority_queue<pll, vector<pll>, greater<pll>> pqkaburi;
    unordered_set<ll> us;
    for(int i = 0; i < n; i++)
    {
        ll t,d;
        cin>>t>>d;
        v[i]=make_pair(d,t);
        pqall.push(v[i]);
    }
    for(int i = 0; i < k; i++)
    {
        pll top = pqall.top();
        pqall.pop();
        if(us.find(top.second)==us.end())
        {
            us.insert(top.second);
            osum+=top.first;
        }
        else
        {
            pqkaburi.push(top);
            osum+=top.first;
        }
    }
    tmp=osum+us.size()*us.size();
    ans=max(ans,tmp);
    while(us.size()<k && pqall.size()>0){
        pll top = pqall.top();
        pqall.pop();
        if(us.find(top.second)==us.end())
        {
            us.insert(top.second);
            osum+=top.first;
            pll del = pqkaburi.top();
            pqkaburi.pop();
            osum-=del.first;
            tmp=osum+us.size()*us.size();
            ans=max(ans,tmp);
        }
    }
    
    cout<<ans<<endl;
    return 0;
}