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
        ll n,k;
        cin>>n>>k;
        vector<ll> m(n);
        for (int i = 0; i < n; i++)
        {
            cin>>m[i];
        }
        vector<ll> diff(n-1);
        for (int i = 0; i < n-1; i++)
        {
            diff[i]=m[i+1]-m[i];
        }
        sort(all(diff));
        reverse(all(diff));
        ll lo=1,hi=diff[0];
        ll ans=1e9+7;
        while (lo<hi)
        {
            ll mid=(lo+hi)/2;
            ll sum=0;
            for (int i = 0; i < n-1; i++)
            {
                if(diff[i]<=mid) break;
                sum+=(diff[i]+mid-1)/mid-1;
            }
            ll sum2=0;
            ll mid2=mid-1;
            for (int i = 0; i < n-1; i++)
            {
                if(diff[i]<=mid2 || mid2<=0) break;
                sum2+=(diff[i]+mid2-1)/(mid2) -1;
            }
            //cout<<lo<<"\t"<<hi<<"\t"<<mid<<"\t"<<sum<<"\t"<<mid2<<"\t"<<sum2<<endl;
            if(sum<=k && k<sum2) break;

            if(sum<=k)
            {
                hi=mid;
            }
            else
            {
                lo=mid;
            }
            
        }   
        cout<<(lo+hi)/2<<endl;

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