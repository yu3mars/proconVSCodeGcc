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
    int n;
    cin>>n;
    vector<tsii> v(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        int p;
        cin>>s>>p;
        v[i] = make_tuple(s,-p,i+1);
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        cout<<get<2>(v[i])<<endl;
    }
        
    
    return 0;
}