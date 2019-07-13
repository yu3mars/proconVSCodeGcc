#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }
    for (int i = 0; i < n-2; i++)
    {
        if((l[i]<=l[i+1] && l[i+1]<=l[i+2]) ||(l[i]>=l[i+1] && l[i+1]>=l[i+2]))
        {
            ans++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}