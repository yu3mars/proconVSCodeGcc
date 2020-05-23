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

int conv(string s, int i)
{
    return s[i] - 'A';
}

int main()
{
    ll n;
    vector<ll> a(3);
    cin >> n;
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    vector<string> s(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    s[n] = s[n - 1];
    vector<int> ans(n);
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        int now0 = conv(s[i], 0);
        int now1 = conv(s[i], 1);
        int next0 = conv(s[i + 1], 0);
        int next1 = conv(s[i + 1], 1);

        if (a[now0] <= 0 && a[now1] <= 0)
        {
            ok = false;
            break;
        }
        if (a[now0] == 0)
        {
            ans[i] = now0;
            a[now0]++;
            a[now1]--;
        }
        else if (a[now1] == 0)
        {
            ans[i] = now1;
            a[now1]++;
            a[now0]--;
        }
        else //docchi demo ok
        {

            if (now0 == 0 && next0 == 0) // both has A
            {
                ans[i] = now0;
                a[now0]++;
                a[now1]--;
            }
            else if (now1 == 2 && next1 == 2) // both has C
            {
                ans[i] = now1;
                a[now1]++;
                a[now0]--;
            }
            else // both has B
            {
                if (now0 == 1)
                {
                    ans[i] = now0;
                    a[now0]++;
                    a[now1]--;
                }
                else
                {
                    ans[i] = now1;
                    a[now1]++;
                    a[now0]--;
                }
            }
        }
    }

    if (ok)
    {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << (char)(ans[i] + 'A') << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}