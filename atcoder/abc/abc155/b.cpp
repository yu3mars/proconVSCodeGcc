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
    bool ok=true;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        if(a%2==0)
        {
            if(a%3==0 || a%5==0)
            {

            }
            else
            {
                ok=false;
            }
            
        }
    }
    if(ok) cout<<"APPROVED"<<endl;
    else cout<<"DENIED"<<endl;
    
    return 0;
}