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


int main(){
    ll INF = __LONG_LONG_MAX__/100;
    ll n,m;
    cin>>n>>m;
    unordered_set<ll> op[n];
    vector<pair<ll,vector<ll>>> v(m+1); //cost, vec
    vector<ll> vtmp;
    for (int i = 0; i < n; i++)
    {
        vtmp.push_back(i);
        op[i].insert(0);
    }
    v[0]=(make_pair(INF,vtmp));
    
    for (int i = 1; i <= m; i++)
    {
        ll a,b;
        cin>>a>>b;
        vector<ll> c(b);
        for (int j = 0; j < b; j++)
        {
            cin>>c[j];
            c[j]--;
            op[c[j]].insert(i);
        }
        v[i]=make_pair(a,c);
    }
    
    //initialize
    vector<ll> used(n);
    ll cost;
    for (int i = 0; i < n; i++)
    {
        used[i]=0;
        
    }
    cost=INF;

    for (int kagiId = 1; kagiId <= m; kagiId++)
    {
        vector<ll> tmpUsed(n);
        for (int i = 0; i < n; i++)
        {
            if(op[i].find(kagiId)!=op[i].end())
            {
                tmpUsed[i]=kagiId;
            }
            else
            {
                tmpUsed[i]=used[i];
            }           
        }
        unordered_set<ll> tmpUsedSet;
        for (int i = 0; i < n; i++)
        {
            tmpUsedSet.insert(tmpUsed[i]);
        }
        ll tmpCost=0;
        for (auto i = tmpUsedSet.begin(); i != tmpUsedSet.end(); i++)
        {
            ll tmpKagiId = *i;
            //cout<<tmpKagiId<<" "<<v[tmpKagiId].first<<endl;
            tmpCost+=v[tmpKagiId].first;
        }
        if(cost>tmpCost)
        {
            for (int i = 0; i < n; i++)
            {
                used[i]=tmpUsed[i];
            }
            cost=tmpCost;
        }
    }
    
    if(cost>=INF)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<cost<<endl;
    }
    cout<<"";

    return 0;
}
