#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int x,ans=1;
    cin>>x;
    
    for(int i = 2; i*i <= x; i++)
    {
        int tmp = 1;
        for(int j = 2; j < x; j++)
        {
            tmp*=i;
            if(tmp>x)break;
            ans=max(ans,tmp);
        }
        
    }
    cout <<ans<<endl;

    return 0;
}