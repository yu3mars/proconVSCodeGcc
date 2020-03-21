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
    int n;
    string s;
    int ans=0;
    cin>>n>>s;
    bool a[10],b[100],c[1000];
    m0(a);
    m0(b);
    m0(c);
    for (int i = 0; i < n; i++)
    {
        int num=s[i]-'0';
        for (int j = 0; j < 100; j++)
        {
            if(b[j]==true)
            {
                c[j*10+num]=true;
            }
        }
        for (int j = 0; j < 10; j++)
        {
            if(a[j]==true)
            {
                b[j*10+num]=true;
            }
        }
        a[num]=true;
    }
    for (int i = 0; i < 1000; i++)
    {
        if(c[i]==true)
        {
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}