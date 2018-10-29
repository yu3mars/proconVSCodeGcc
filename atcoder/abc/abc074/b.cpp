#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,k,ans=0;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans += min(x, k-x);
    }
    

    cout << ans * 2 << endl;

    return 0;
}