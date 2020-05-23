#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

class GoogleCodeJam
{
public:
    string case_prefix;
    void exec()
    {
        ll n,d;
        cin>>n>>d;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        sort(all(a));
        
        unordered_map<ll,ll> mp;
        for (int i = 0; i < n; i++)
        {
            if(mp.find(a[i])==mp.end())
            {
                mp.emplace(a[i],1);
            }
            else 
            {
                mp[a[i]]++;
            }
        }
        
        ll ans=d-1;
        if(d<=3)
        {
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if((it->second) >=d)
                {
                    ans=min(ans,0LL);
                }
                else if((it->second) ==d-1)
                {
                    ans=min(ans,1LL);
                }
                else if(mp.find((it->first)*2)!=mp.end())
                {
                    ans=min(ans,1LL);
                }
            }
        }

        cout<<ans<<endl;
    }
    GoogleCodeJam()
    {
        int T;
        std::cin >> T;
        for (int i = 1; i <= T; i++)
        {
            case_prefix = "Case #" + std::to_string(i) + ": ";
            cout << case_prefix;
            exec();
        }
    }
};

int main()
{
    GoogleCodeJam();

    return 0;
}