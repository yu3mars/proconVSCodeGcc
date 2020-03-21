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
    int a[3][3];
    bool ok[3][3],yes=false;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>a[i][j];
            ok[i][j]=false;
        }
    }
    int n;
    cin>>n;
    vector<int> b(n);
    for (int k = 0; k < n; k++)
    {
        cin>>b[k];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(b[k]==a[i][j])
                {
                    ok[i][j]=true;
                }
            }
        }
    }
    
    //yoko
    for (int i = 0; i < 3; i++)
    {
        if(ok[i][0]==true && ok[i][1]==true && ok[i][2]==true) yes=true;
        if(ok[0][i]==true && ok[1][i]==true && ok[2][i]==true) yes=true;
    }
    if(ok[0][0]==true && ok[1][1]==true && ok[2][2]==true) yes=true;
    if(ok[0][2]==true && ok[1][1]==true && ok[2][0]==true) yes=true;

    if(yes==true) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}