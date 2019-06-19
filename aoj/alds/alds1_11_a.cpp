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



int main(){
    int n;
    cin>>n;
    int ls[110][110];
    m0(ls);
    for(int i = 0; i < n; i++)
    {
        int from,cnt;
        cin>>from>>cnt;
        from--;
        for(int j = 0; j < cnt; j++)
        {
            int to;
            cin>>to;
            to--;
            ls[from][to]=1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j>0)cout<<" ";
            cout<<ls[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}