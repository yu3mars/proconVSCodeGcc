#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};


int main()
{
    int n,pcnt=-1,qcnt=-1;
    cin>>n;
    vector<int> p(n),q(n),v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>q[i];
    }
    for (int i = 0; i < n; i++)
    {
        v[i]=i+1;
    }
    int n2=1;
    for (int i = n; i > 0; i--)
    {
        n2*=i;
    }
    
    for (int i = 0; i < n2; i++)
    {
        if(v==p)
        {
            pcnt=i;
        }
        if(v==q)
        {
            qcnt=i;
        }
        next_permutation(v.begin(), v.end());
    }
    cout<<abs(pcnt-qcnt)<<endl;
    
    return 0;
}