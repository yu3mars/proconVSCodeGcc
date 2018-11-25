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
    int n,x,ans=0;
    cin>>n>>x;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    
    for(int i = 0; i < n; i++)
    {
        if(x>=a[i])
        {
            x-=a[i];
            ans++;
            if(i==n-1 && x>0)
            {
                ans--;
            }
        }
        else break;
    }
    cout<<ans<<endl;

    return 0;
}