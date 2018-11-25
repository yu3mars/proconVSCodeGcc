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
    int n,m;
    cin >>n>>m;
    vector<int> p(m),y(m),ansy(m);
    vector<pii> city[100100];
    
    for(int i = 0; i < m; i++)
    {
        cin >> p.at(i)>>y.at(i);
        city[p.at(i)-1].push_back(pii(y.at(i),i));
    }
    
    for(int i = 0; i < n; i++)
    {
        sort(all(city[i]));
        
        for(int j = 0; j < city[i].size(); j++)
        {
            ansy.at(city[i].at(j).second) = j+1;
        }        
    }
    
    
    for(int i = 0; i < m; i++)
    {
        cout<<setfill('0')<<right<<setw(6)<<p.at(i);
        cout<<setfill('0')<<right<<setw(6)<<ansy.at(i)<<endl;
    }
    
 
    return 0;
}