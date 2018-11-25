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
    string o,e;
    cin>>o>>e;
    
    for(int i = 0; i < e.size(); i++)
    {
        cout<<o[i]<<e[i];
    }
    if(o.size()>e.size())
    {
        cout<<o[o.size()-1];
    }
    cout<<endl;

    return 0;
}