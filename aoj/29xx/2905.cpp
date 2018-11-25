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
    cin>>n;
    vector<pair<int,string>> l(n);
    
    for(int i = 0; i < n; i++)
    {
        string cc;
        int dd;
        cin>>cc>>dd;
        l[i]=make_pair(dd,cc);
    }
    sort(all(l));
    cin>>m;
    vector<string> o(m);
    for(int i = 0; i < m; i++)
    {
        cin>>o[i];
    }
    
    int nowd = 0;
    int nowo = 0;
    
    for(int liq = 0; liq < n; liq++)
    {
        if(get<0>(l[liq])>nowd && get<1>(l[liq])==o[nowo])
        {
            nowd = get<0>(l[liq]);
            nowo++;
            if(nowo==m) break;
        }
    }
    
    if(nowo==m) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}