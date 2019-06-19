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
    vector<int> v(3);
    for (int i = 0; i < 3; i++)
    {
        cin>>v[i];
    }
    sort(all(v));
    cout<<v[0]+v[1]<<endl;

    return 0;
}