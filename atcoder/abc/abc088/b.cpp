#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    
    sort(all(a));
    reverse(all(a));
    
    for(int i = 0; i < n; i++)
    {
        if(i%2==0)
        {
            ans+=a.at(i);
        }
        else
        {
            ans-=a.at(i);
        }
    }
    
    cout << ans << endl;

    return 0;
}