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

bool check(vector<pll> v)
{
    int sm=0;
    for (int i = 0; i < v.size(); i++)
    {
        if(sm+v[i].first<0) return false;
        sm+=v[i].second;
    }
    return true;
}

int main()
{
    ll n,total=0;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<pll> p, m;
    for (int i = 0; i < n; i++)
    {
        ll mi = 0, su = 0; //min,sum

        for (int j = 0; j < s[i].size(); j++)
        {
            char c = s[i][j];
            if (c == '(')
            {
                su++;
            }
            else
            {
                su--;
                mi = min(mi, su);
            }
        }
        if (su >= 0)
        {
            p.push_back(make_pair(mi, su));
        }
        else
        {
            m.push_back(make_pair(mi-su,-su));
        }
        total+=su;
    }
    sort(all(p));
    reverse(all(p));
    sort(all(m));
    reverse(all(m));


    if (check(p) && check(m) && total==0)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;

    return 0;
}