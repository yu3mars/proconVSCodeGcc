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

ll mod = 1e9+7;
vector<ll> ls[100010];
ll parentCnt[100010];
bool visited[100010];
ll n,k,ans=1;

int main()
{
    cin>>n>>k;
    vector<ll> a(n-1),b(n-1);

    for (int i = 0; i < n-1; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    m0(parentCnt);
    m0(visited);
    for (int i = 0; i < n-1; i++)
    {
        ls[a[i]].push_back(b[i]);
        ls[b[i]].push_back(a[i]);
    }
    
    queue<pair<ll,ll>> q; //now, parent
    visited[0]=true;
    for (int i = 0; i < ls[0].size(); i++)
    {
        q.push(make_pair(ls[0][i],0));
        visited[ls[0][i]]=true;
    }
    parentCnt[0]=1;
    ans*=k;
    ans%=mod;
    visited[0]=true;
    while (q.size()>0)
    {
        pll p = q.front();
        q.pop();
        ll now = p.first;
        ll parent = p.second;
        ans*=(k-parentCnt[parent]);
        ans%=mod;
        
        //cout<<now<<" "<<ans<<" "<<parentCnt[parent] <<endl;
        parentCnt[parent]++;
        parentCnt[now]+=2;
        
        for (int i = 0; i < ls[now].size(); i++)
        {
            ll next = ls[now][i];
            if(visited[next] == false)
            {
                q.push(make_pair(ls[now][i], now));
                visited[next] = true;
            }
        }
    }
    
    
    cout<<ans<<endl;
    return 0;
}