#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

vector<ll> v[510000];

int main()
{
    int h,w,d;
    ll ans=0;
    cin>>h>>w>>d;
    vector<tuple<int,int,int>> a;//num,x,y
    int dist[90010];
    
    
    for(int hh = 0; hh < h; hh++)
    {
        for(int ww = 0; ww < w; ww++)
        {
            int nnn;
            cin>>nnn;
            a.push_back(make_tuple(nnn-1,ww,hh));
        }        
    }
    sort(all(a)); 
    
    for(int i = 0; i < 90010; i++)
    {
        dist[i]=0;
    }
    
    for(int i = 0; i <= a.size(); i++)
    {
        if(i+d<=a.size())
        {
            dist[i+d]=dist[i]
            +abs(get<1>(a[i+d])-get<1>(a[i]))
            +abs(get<2>(a[i+d])-get<2>(a[i]));
        }
    }
    
    int q;
    cin>>q;
    
    for(int qq = 0; qq < q; qq++)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<dist[r]-dist[l]<<endl;
    }
    

    return 0;
}