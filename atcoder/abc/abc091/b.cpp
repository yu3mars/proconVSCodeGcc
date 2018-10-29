#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,m,ans=0;
    cin >> n;
    vector<string> s(n);

    
    for(int i = 0; i < n; i++)
    {
        cin >> s.at(i);
    }

    cin >> m;
    vector<string> t(m);
    
    for(int i = 0; i < m; i++)
    {
        cin >> t.at(i);
    }

    
    for(int j = 0; j < n; j++)
    {
        int tmp = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s.at(j)==s.at(i)) tmp++;
        }
        
        for(int i = 0; i < m; i++)
        {
            if(s.at(j) == t.at(i)) tmp--;
        }
        
        ans=max(ans,tmp);
    }
    
    
    cout << ans << endl;

    return 0;
}