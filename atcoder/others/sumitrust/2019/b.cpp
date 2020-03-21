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
    int n;
    cin>>n;
    double dmoto = n/1.08;
    int imoto=(int)dmoto;
    int ans=-1;
    for (int i = 0; i < 3; i++)
    {
        if((int)((imoto+i)*1.08)==n)
        {
            ans=imoto+i;
        }
    }
    
    if(ans>0)
    {
        cout<<ans<<endl;
    }
    else
    {
        cout<<":("<<endl;
    }
    
    return 0;
}