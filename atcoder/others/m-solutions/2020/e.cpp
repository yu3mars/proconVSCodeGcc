#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define m0(x) memset(x, 0, sizeof(x))

int dx4[4] = {1, 0, -1, 0}, dy4[4] = {0, 1, 0, -1};

ll INF = __LONG_LONG_MAX__ / 3;

int bitCount(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> p[i];
    }
    vector<ll> ans(n + 1);
    for (int i = 0; i <= n; i++)
    {
        ans[i] = INF;
    }
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int bitCnt = bitCount(bit);
        if (bitCnt == n)
        {
            ans[n] = 0;
            continue;
        }

        for (int xybit = 0; xybit < (1 << bitCnt); xybit++)
        {
            vector<ll> vx, vy;
            vx.push_back(0);
            vy.push_back(0);
            int xyCnt=0;
            ll score=0;
            for (int i = 0; i < n; i++)
            {
                if((bit & (1<<i))>0)
                {
                    if((xybit & (1<<xyCnt))>0)
                    {
                        vx.push_back(x[i]);
                    }
                    else
                    {
                        vy.push_back(y[i]);
                    }
                }
            }
            
            for (int i = 0; i < n; i++)
            {
                if((bit & (1<<i))>0) continue;

                ll dist = abs(x[i]);
                for (int xx = 0; xx < vx.size(); xx++)
                {
                    dist=min(dist,abs(x[i] -vx[xx]));
                }
                for (int yy = 0; yy < vy.size(); yy++)
                {
                    dist=min(dist,abs(y[i] -vy[yy]));
                }
                score+=dist*p[i];
            }
            ans[bitCnt]= min(ans[bitCnt], score);
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}