#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using psi = pair<string,int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int nn;
    cin>>nn;
    vector<psi> ls[11];
    ls[0].push_back(make_pair("a",1));
    for (int n = 1; n < nn; n++)
    {
        for (int i = 0; i < ls[n-1].size(); i++)
        {
            auto now = ls[n-1][i];
            for (int j = 0; j < now.second; j++)
            {
                psi next=make_pair(now.first+(char)('a'+j),now.second);
                ls[n].push_back(next);
            }
            psi next=make_pair(now.first+(char)('a'+now.second),now.second+1);
            ls[n].push_back(next);
        }
    }
    
    for (int i = 0; i < ls[nn-1].size(); i++)
    {
        cout<<ls[nn-1][i].first<<endl;
    }
    
    
    return 0;
}