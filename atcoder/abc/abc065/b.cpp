#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    int n,now=0,ans=0;
    cin >> n;

    vector<int> a(n);
    vector<bool> b(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        a.at(i)--;
    }
    
    while(true){
        if(b.at(now)) break;
        b.at(now)=true;
        now=a.at(now);
        ans++;
        if(now==1)
        {
            cout << ans<<endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}