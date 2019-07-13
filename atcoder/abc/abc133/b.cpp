#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tsii = tuple<string, int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int n,d,ans=0;
    cin>>n>>d;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double dist = 0;
            for (int k = 0; k < d; k++)
            {
                dist += pow(v[i][k] - v[j][k], 2); 
            }
            dist = sqrt(dist);
            if(dist == (int)(dist))
            {
                ans++;
            }
        }
        
    }
    

    cout<<ans<<endl;
    return 0;
}