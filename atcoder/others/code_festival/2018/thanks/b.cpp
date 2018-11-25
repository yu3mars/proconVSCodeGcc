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
    int x,y;
    string ans="Yes";
    cin>>x>>y;
    if(x>y)swap(x,y);

    if((x+y)%4!=0) ans="No";
    else
    {
        int diff = y-x;
        if(diff%2>0) ans="No";
        else
        {
            x-=diff/2;
            y-=diff*3/2;
            if(x==y && x%4==0 &&x>=0)
            {

            }
            else
            {
                ans="No";
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}