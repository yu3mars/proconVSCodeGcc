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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int qq = 0; qq < q; qq++)
    {
        int com,b,e;
        cin>>com>>b>>e;
        if(com==0)//min
        {
            int ans=INT_MAX;
            for(int i = b; i < e; i++)
            {
                ans=min(ans,a[i]);
            }
            cout<<ans<<endl;
        }
        else
        {
            int ans=INT_MIN;
            for(int i = b; i < e; i++)
            {
                ans=max(ans,a[i]);
            }
            cout<<ans<<endl;
        }
        
    }
    

    return 0;
}