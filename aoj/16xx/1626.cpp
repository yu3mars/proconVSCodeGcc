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
    for(;;)
    {
        ll b;
        cin>>b;
        if(b==0)break;
        ll ansbgn = b, anscnt=1;

        
        for(ll n = 2; n <= b; n++)
        {
            ll sm = n*(n+1)/2;
            if(sm >b) break;
            if((b-sm)%n==0)
            {
                ll k = (b-sm)/n;
                anscnt=n;
                ansbgn=k+1;
            }
        }
        
        cout << ansbgn<<" "<<anscnt<<endl;
    }

    return 0;
}