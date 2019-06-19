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


int main()
{
    int n[3],mx[3];
    int kk;
    for(int i = 0; i < 3; i++)
    {
        cin>>n[i];
    }
    cin>>kk;
    vector<ll> v[3];
    for(int i = 0; i < 3; i++)
    {
        v[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++)
        {
            cin>>v[i][j];
        }
        sort(all(v[i]));
        reverse(all(v[i]));

    }

    vector<ll> ans;
    for(int i = 0; i < n[0]; i++)
    {
        for(int j = 0; j < n[1]; j++)
        {
            for(int k = 0; k < n[2]; k++)
            {
                if(i*j*k<kk)
                {
                    ans.push_back(v[0][i]+v[1][j]+v[2][k]);
                }
                else break;
            }
            
        }
        
    }
    sort(all(ans));
    reverse(all(ans));
    for(int i = 0; i < kk; i++)
    {
        cout<<ans[i]<<endl;
    }
    
    

    return 0;
}