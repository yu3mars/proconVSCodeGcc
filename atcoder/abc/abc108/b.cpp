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
    int x[4],y[4];
    
    for(int i = 0; i < 2; i++)
    {
        cin>>x[i]>>y[i];
    }
    int dx = x[1]-x[0];
    int dy = y[1]-y[0];
    x[2]= x[1]-dy;
    y[2]=y[1]+dx;
    x[3]=x[2]-dx;
    y[3]=y[2]-dy;

    cout<<x[2]<<" "<<y[2]<<" "<<x[3]<<" "<<y[3]<<endl;

    return 0;
}