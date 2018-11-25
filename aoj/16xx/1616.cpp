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
    for(;;)
    {
        int n,m,ans=-1;
        cin>>n>>m;
        if(n==0) break;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(a[i]+a[j]<=m)
                {
                    ans=max(ans,a[i]+a[j]);
                }
            }            
        }
        if(ans>=0)
        {
            cout << ans<<endl;
        }
        else
        {
            cout<<"NONE"<<endl;
        }
    }
    return 0;
}