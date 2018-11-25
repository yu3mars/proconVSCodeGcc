#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string> a(n),b(m);
    
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for(int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    
    bool ok = false;
    for(int y = 0; y < n-m+1; y++)
    {
        for(int x = 0; x < n-m+1; x++)
        {
            bool ok2 = true;                    
            for(int yy = 0; yy < m; yy++)
            {
                if(a[y+yy].substr(x,m) != b[yy])
                {
                    ok2 = false;
                    break;
                }
            }
            if(ok2) 
            {
                ok=true;
                break;
            }
        }
        if(ok)
        {
            break;
        }
    }

    if(ok)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}