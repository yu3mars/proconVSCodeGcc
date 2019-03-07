#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int ls[30][200010];

int main()
{
    int n,cc,ans=0;
    cin >> n >> cc;
    vector<int> s(n),t(n),c(n);
    m0(ls);
    for(int i = 0; i < n; i++)
    {
        cin>>s[i]>>t[i]>>c[i];
        c[i]--;
        ls[c[i]][s[i]*2]++;
        ls[c[i]][t[i]*2+1]--;
    }
    for(int i = 1; i < 200005; i++)
    {
        for(int ccc = 0; ccc < 30; ccc++)
        {
            ls[ccc][i]=ls[ccc][i-1]+ls[ccc][i];
        }
    }
    for(int i = 2; i < 200005; i+=2)
    {
        for(int ccc = 0; ccc < 30; ccc++)
        {
            if(ls[ccc][i]>0)
            {
                ls[ccc][i-1]++;
            }
        }
    }
    
    for(int i = 0; i < 200005; i++)
    {
        int tmp=0;
        for(int ccc = 0; ccc < 30; ccc++)
        {
            if(ls[ccc][i]>0)
            {
                tmp++;
            } 
        }
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;
    return 0;
}