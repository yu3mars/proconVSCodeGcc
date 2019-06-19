#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

const int MAX = 110;
const ll INF = __LONG_LONG_MAX__/3;

int n;
ll d[MAX][MAX];

void warshallFloyd()
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(d[i][k]==INF) continue;
            for(int j = 0; j < n; j++)
            {
                if(d[k][j]==INF) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int e;
    cin>>n>>e;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j)
            {
                d[i][j]=0;
            }
            else
            {
                d[i][j]=INF;
            }
        }
    }
    
    for(int i = 0; i < e; i++)
    {
        ll s,t,dd;
        cin>>s>>t>>dd;
        d[s][t]=dd;
        //d[t][s]=dd;
    }

    warshallFloyd();

    bool negative = false;
    for(int i = 0; i < n; i++)
    {
        if(d[i][i]<0) 
        {
            negative=true;
            break;
        }
    }
    if(negative)
    {
        cout<<"NEGATIVE CYCLE"<<endl;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j>0) cout<<" ";
                if(d[i][j]==INF)
                {
                    cout<<"INF";
                }
                else
                {
                    cout<<d[i][j];
                }
            }
            cout<<endl;
        }
    }
    
    return 0;
}