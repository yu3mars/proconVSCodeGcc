#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

// Combination Table 
ll C[51][51]; // C[n][k] -> nCk 

void comb_table (int N)
{ 
    for (int i = 0 ;i <= N; i++)
    { 
        for (int j = 0 ;j <= i; j++)
        { 
            if (j == 0 or j == i)
            {
                C[i][j] = 1LL; 
            }
            else
            { 
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]); 
            } 
        } 
    } 
}

int main()
{
    int n,a,b;
    ll ans=0;
    double ave=0;
    cin>>n>>a>>b;
    vector<ll> v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(all(v));
    reverse(all(v));
    comb_table(n);
    
    for(int i = 0; i < a; i++)
    {
        ave+=v[i];
    }
    ave/=a;
    int mincnt=0;
    int maxcnt=0;
        
    for(int i = 0; i < n; i++)
    {
        if(v[i]==v[a-1]) 
        {
            maxcnt++;
            if(i<a) mincnt++;
        }
    }
    

    if(v[0]==v[a-1])
    {
        for(int i = mincnt; i <= min(b,maxcnt); i++)
        {
            ans+=C[maxcnt][i];
        }
    }
    else
    {
        ans+=C[maxcnt][mincnt];
    }
    

    cout<<fixed;
    cout<<ave<<endl;
    cout<<ans<<endl;

    return 0;
}