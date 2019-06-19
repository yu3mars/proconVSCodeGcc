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
    int n,m;
    cin>>n>>m;
    int ansl=1,ansr=n;
    for (int i = 0; i < m; i++)
    {
        int l,r;
        cin>>l>>r;
        ansl=max(ansl,l);
        ansr=min(ansr,r);
    }
    cout<<max(0,ansr-ansl+1)<<endl;;

    return 0;
}