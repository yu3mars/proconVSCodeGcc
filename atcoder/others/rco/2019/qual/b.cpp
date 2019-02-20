#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    int n,m;
    cin>>n>>m;
    int a[50][50];
    for(int yy = 0; yy < n; yy++)
    {
        for(int xx = 0; xx < n; xx++)
        {
            cin>>a[yy][xx];
        }        
    }
    
    int opcnt = 0;

    for(int yy = 0; yy < n; yy++)
    {
        for(int xx = 0; xx < n; xx++)
        {
            if(opcnt>=m) 
            {
                return 0;
            }
            cout<<2<<" "<<yy<<" "<<xx<<endl;
            opcnt++;
        }        
    }
    while(opcnt < m){
        cout<<"1 0 0"<<endl;
        opcnt++;
    }
    
    
    
    return 0;
}