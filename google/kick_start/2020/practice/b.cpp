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
        int n;
        string s;
        cin>>n>>s;
        int ans=0,tmp=0;
        for (int i = 0; i < (n+1)/2; i++)
        {
            tmp+=s[i]-'0';
        }
        ans=tmp;
        for (int i = (n+1)/2; i < n; i++)
        {
            tmp+=s[i]-s[i-(n+1)/2];
            ans=max(ans,tmp);
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