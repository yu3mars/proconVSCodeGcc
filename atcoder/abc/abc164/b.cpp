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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while (true)
    {
        c-=b;
        if(c<=0)
        {
            cout<<"Yes"<<endl;
            break;
        }
        a-=d;
        if(a<=0)
        {
            cout<<"No"<<endl;
            break;
        }
    }
    
    return 0;
}