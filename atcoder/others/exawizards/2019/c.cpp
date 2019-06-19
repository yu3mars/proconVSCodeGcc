#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int n,q;
string s;
vector<char> t,d;

int simu(int k)
{
    int ret=0;
    for(int i = 0; i < q; i++)
    {
        int tt=t[i];
        if(s[k]==tt)
        {
            char dd = d[i];
            if(dd=='L')
            {
                k--;
                if(k<0) return -1;
            }
            else
            {
                k++;
                if(k>=n) return 1;
            }
            
        }
    }
    

    return ret;
}

int main()
{
    cin>>n>>q>>s;
    t.resize(q);
    d.resize(q);
    for(int i = 0; i < q; i++)
    {
        cin>>t[i]>>d[i];
    }
    int lans,rans;
    int l,r;

    // hidari haji wo sagasu
    l=0;
    r=n;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(simu(mid)==-1)
        {
            l=mid+1;
        }
        else 
        {
            r=mid;
        }
    }
    lans=l;

    // migi haji wo sagasu
    l=0;
    r=n;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(simu(mid)!=1)
        {
            l=mid+1;
        }
        else 
        {
            r=mid;
        }
    }
    rans=l;

    cout<<rans-lans<<endl;
 
    return 0;
}