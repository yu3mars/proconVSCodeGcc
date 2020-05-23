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
    int k,a,b;
    cin>>k>>a>>b;
    int tmp=0;
    bool ok=false;
    while (tmp<=b)
    {
        tmp+=k;
        if(a<=tmp && tmp <=b) ok=true;
    }
    if(ok) cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
    
    
    return 0;
}