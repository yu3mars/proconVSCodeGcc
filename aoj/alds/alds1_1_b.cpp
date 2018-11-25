#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int gcd(int x, int y)
{
    if(x < y) 
    {
        swap(x,y);
    }
    while(y>0)
    {
        int r = x%y;
        x=y;
        y=r;
    }
    return x;
}

int main()
{
    int x,y;
    cin >> x>>y;
    
    cout << gcd(x,y) << endl;
    //cout << __gcd(x,y) << endl;
 
    return 0;
}