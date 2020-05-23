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
        int n,k,p;
        cin>>n>>k>>p;
        vector<vector<int>> v(n);
        for (int ni = 0; ni < n; ni++)
        {
            for (int ki = 0; ki < k; ki++)
            {
                int vv;
                cin>>vv;
                v[ni].push_back(vv);
            }
        }
        int dp[2][2000]; //bef, aft i=saraCnt
        m0(dp);

        for (int ni = 0; ni < n; ni++)
        {
            int sum=0;
            for (int ki = 0; ki < k; ki++)
            {
                sum+=v[ni][ki];
                for (int i = 0; i < n*k+10; i++)
                {
                    dp[1][i+ki+1]=max(dp[1][i+ki+1],dp[0][i]+sum);
                }
            }
            for (int i = 0; i < 2000; i++)
            {
                dp[0][i]=dp[1][i];
            }
        }

        cout<<dp[0][p]<<endl;
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