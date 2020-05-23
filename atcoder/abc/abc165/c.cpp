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

ll n, m, q;
vector<int> a, b, c, d;
vector<int> v;

int judge(vector<int> vec)
{
    int score = 0;
    for (int i = 0; i < q; i++)
    {
        if (vec[b[i]] - vec[a[i]] == c[i])
        {
            score += d[i];
        }
    }

    return score;
}

int main()
{
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    v.resize(n);
    for (int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        vector<int> tmp1(n), tmp2(n);
        for (int j = 0; j < n; j++)
        {
            tmp1[j] = v[j];
            tmp2[j] = v[j];
        }
        if (tmp1[a[i]] + c[i] < m)
        {
            tmp1[b[i]] = tmp1[a[i]] + c[i];
            for (int j = b[i] - 1; j >= 0; j--)
            {
                tmp1[j]=min(tmp1[j],tmp1[b[i]]);
            }
            
            int tmpscore = judge(tmp1);
            if (ans < tmpscore)
            {
                v[b[i]] = tmp1[a[i]] + c[i];
                ans=tmpscore;
            }
            //cout<<tmpscore<<endl;//
        }
        if (0 <= tmp2[b[i]] - c[i])
        {
            tmp2[a[i]] = tmp2[b[i]] - c[i];
            for (int j = a[i]+1; j < n; j++)
            {
                tmp2[j]=max(tmp2[j],tmp2[a[i]]);
            }
            

            int tmpscore = judge(tmp2);
            if (ans < tmpscore)
            {
                v[a[i]] = tmp2[b[i]] - c[i];
                ans=tmpscore;
            }
            //cout<<tmpscore<<endl;//
        }
    }

    cout << ans << endl;

    return 0;
}