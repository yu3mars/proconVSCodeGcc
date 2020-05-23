#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

int h, w;
vector<string> s;
int dp[110][110];

bool inside(int y, int x)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        string ss;
        cin >> ss;
        s.push_back(ss);
    }
    m0(dp);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            dp[i][j] = 1e9 + 7;
        }
    }
    if (s[0][0] == '.')
    {
        dp[0][0] = 0;
    }
    else
    {
        dp[0][0] = 1;
    }

    for (int ww = 0; ww < w; ww++)
    {
        for (int hh = 0; hh < h; hh++)
        {
            int befh = hh - 1;
            if (inside(befh, ww))
            {
                if (s[hh][ww] != s[befh][ww])
                {
                    dp[hh][ww] = min(dp[hh][ww], dp[befh][ww] + 1);
                }
                else
                {
                    dp[hh][ww] = min(dp[hh][ww], dp[befh][ww]);
                }
            }
            int befw = ww - 1;
            if (inside(hh, befw))
            {
                if (s[hh][ww] != s[hh][befw])
                {
                    dp[hh][ww] = min(dp[hh][ww], dp[hh][befw] + 1);
                }
                else
                {
                    dp[hh][ww] = min(dp[hh][ww], dp[hh][befw]);
                }
            }
        }
    }
    if(s[h - 1][w - 1]=='#') dp[h - 1][w - 1]++;
    cout << dp[h - 1][w - 1]/2 << endl;

    return 0;
}