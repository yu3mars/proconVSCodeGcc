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
    vector<int> a(3);
    for (int i = 0; i < 3; i++)
    {
        cin>>a[i];
    }
    bool ok=false;
    for (int i = 0; i < 3; i++)
    {
        if(a[i%3]==a[(i+1)%3]&& a[i%3]!=a[(i+2)%3])
        {
            ok=true;
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}