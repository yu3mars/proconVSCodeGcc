#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};



int main()
{
    int n,h,ans=0;
    cin >>n>>h;
    vector<int> a(n),b(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    
    sort(all(a));
    sort(all(b));

    int mx = a[n-1];
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(h > 0 && b[i] > mx)
        {
            h-=b[i];
            ans++;
        }
        else
        {
            break;
        }
    }
    if(h>0)
    {
        ans += h/mx;
        if(h%mx>0) ans++;
    }
    cout << ans<<endl;

    return 0;
}