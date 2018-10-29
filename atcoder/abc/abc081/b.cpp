#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,ans=1000000007;
    cin >> n;
    
    
    for(int i = 0; i < n; i++)
    {
        int x,tmp=0;
        cin >> x;
        while(x%2==0)
        {
            x/=2;
            tmp++;
        }
        ans=min(ans,tmp);
    }
    cout << ans << endl;
 
    return 0;
}