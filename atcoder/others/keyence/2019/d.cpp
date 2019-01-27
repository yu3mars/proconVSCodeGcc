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
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    ll ans=1;
    ll mod = 1e9+7;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        a[i]=n*m-a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin>>b[i];
        b[i]=n*m-b[i];
    }
    sort(all(a));
    sort(all(b));
    
    for(int i = 0; i < n-1; i++)
    {
        if(a[i]==a[i+1])
        {
            ans=0;
            break;
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        if(b[i]==b[i+1])
        {
            ans=0;
            break;
        }
    }
    
    
    ll acnt=0;
    ll bcnt=0;
    
    for(int now = 0; now < n*m; now++)
    {
        if(ans==0)
        {
            break;
        }
        if(acnt<n && a[acnt]==now)
        {
            if(bcnt<m && b[bcnt]==now)
            {
                acnt++;
                bcnt++;
            }
            else
            {
                acnt++;
                ans*=bcnt;
                ans%=mod;
            }
        }
        else if(bcnt<m && b[bcnt]==now)
        {
            bcnt++;
            ans*=acnt;
            ans%=mod;
        }
        else
        {
            ll kouho = acnt*bcnt - now;
            if(kouho>0)
            {
                ans*=kouho;
                ans%=mod;
            }
            else
            {
                ans=0;
            }
        }
    }
    


    cout<<ans<<endl;
    return 0;
}