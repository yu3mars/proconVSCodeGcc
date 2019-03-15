#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

ll n,k;
vector<ll> w;

bool check(ll p)
{
    ll trackcnt=1, nowcnt=0;//track_used, now_sekisai
    for(int i = 0; i < n; i++)
    {
        if(w[i]>p)
        {
            return false;
        }
        if(nowcnt+w[i]>p)
        {
            trackcnt++;
            nowcnt=w[i];
        }
        else
        {
            nowcnt+=w[i];
        }
    }
    if(trackcnt<=k)
    { 
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        int ww;
        cin>>ww;
        w.push_back(ww);
    }
    ll lb=0, ub=1e15;
    while(lb+1<ub){
        ll mid=(lb+ub)/2;
        //cout<<mid<<endl;
        if(check(mid))
        {
            ub=mid;
        }
        else
        {
            lb=mid;
        }
    }
    
    cout<<ub<<endl;
    return 0;
}