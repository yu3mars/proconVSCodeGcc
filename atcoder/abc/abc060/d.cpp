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
    int n,w;
    ll w1,ans=0;
    cin>>n>>w;
    vector<ll> v[4];
    ll imos[4][110];
    m0(imos);
    
    for(int i = 0; i < n; i++)
    {
        int ww,vv;
        cin>>ww>>vv;
        if(i==0) 
        {
            w1=ww;
        }
        v[ww-w1].push_back(vv);
    }
    
    for(int i = 0; i < 4; i++)
    {
        sort(all(v[i]));
        reverse(all(v[i]));
    }
    
    for(int i = 0; i < 4; i++)
    {
        imos[i][0]=0;
        for(int j = 0; j < v[i].size(); j++)
        {
            imos[i][j+1] = imos[i][j]+v[i][j];
        }
        
    }
    

    
    ll tmp = 0;
    for(ll i = 0; i <= v[0].size(); i++)
    {
        for(ll j = 0; j <= v[1].size(); j++)
        {
            for(ll k = 0; k <= v[2].size(); k++)
            {
                for(ll l = 0; l <= v[3].size(); l++)
                {
                    if(w>=w1*i+(w1+1)*j+(w1+2)*k+(w1+3)*l)
                    {
                        ll tmp = imos[0][i]+imos[1][j]+imos[2][k]+imos[3][l];
                        ans=max(ans,tmp);
                    }                    
                }
                
            }            
        }
    }
    
    cout<<ans<<endl;

    return 0;
}