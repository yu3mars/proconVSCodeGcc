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
    ll n,k,s;
    cin>>n>>k>>s;
    if(s<(ll)1e9)
    {
        for (int i = 0; i < n; i++)
        {
            if(i<k)
            {
                cout<<s;
            }
            else
            {
                cout<<(ll)1e9;
            }
            
            if(i<n-1)
            {
                cout<<" ";
            }
            else cout<<endl;
        }        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(i<k)
            {
                cout<<s;
            }
            else
            {
                cout<<1;
            }
            
            if(i<n-1)
            {
                cout<<" ";
            }
            else cout<<endl;
        }  
    }
    
    
    return 0;
}