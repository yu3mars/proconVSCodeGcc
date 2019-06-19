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
    int n,k,ans=0;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> v[2];
    int tmp=0;
    if(s[0]=='0') v[1].push_back(0); //v1 kara kazoeru
    for(int i = 0; i < n; i++)
    {
        if(i==0)
        {
            tmp=1;
        }
        else
        {
            if(s[i]==s[i-1])
            {
                tmp++;
            }
            else
            {
                v[s[i-1]-'0'].push_back(tmp);
                tmp=1;
            }
            
        }
        if(i==n-1)
        {
            v[s[i]-'0'].push_back(tmp);
        }
    }
    if(s[n-1]=='0') v[1].push_back(0); //v1 kara kazoeru
    if(v[0].size()<=k)
    {
        ans=s.size();
    }
    else
    {
        int tmp=0;
        for(int i = 0; i < k; i++)
        {
            tmp+=v[0][i]+v[1][i];
        }
        tmp+=v[1][k];
        ans=tmp;
        //cout<<ans<<endl;
        for(int i = 0; i+k < v[0].size(); i++)
        {
            tmp=tmp-v[0][i]-v[1][i];
            tmp+=v[0][i+k]+v[1][i+k+1];
            ans=max(ans,tmp);
            //cout<<i<<"\t"<<i+k<<"\t"<<tmp<<endl;
        }
        
    }
    

    cout<<ans<<endl;
    return 0;
}