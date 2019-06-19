#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int n,x;
vector<int> s;
ll ans,mod=1e9+7;


int main()
{
    ans=0;
    cin>>n>>x;
    s.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    sort(all(s));

    set<int> se;
    map<int,int> ma;
    while(true)
    {
        int tmp=x;
        for(int i = 0; i < n; i++)
        {
            tmp%=s[i];
        }
        se.insert(tmp);
        if(ma.find(tmp)!=ma.end())
        {
            ma[tmp]++;
        }
        else ma.insert(make_pair(tmp,1));
        //cout<<tmp<<endl;
        ans+=tmp;
        ans%=mod;
        
        if(next_permutation(all(s))==false)
        {
            break;
        }
    }
    for(auto i = ma.begin(); i !=ma.end(); i++)
    {
        cout<<(*i).first<<"\t"<<(*i).second<<endl;
    }
    

    cout<<ans<<endl;
 
    return 0;
}