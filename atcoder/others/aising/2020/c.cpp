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

int main()
{
    int nn;
    cin >> nn;
    for (int n = 1; n <= nn; n++)
    {
        int ans = 0;
        for (int x = 1; x * x + 2 * x + 3 <= n; x++)
        {
            for (int y = 1; x * x + y * y + 1 + x * y + y + x <= n; y++)
            {
                int b=x+y;
                int c=x*x+y*y+x*y-n;
                int zz = (-b+sqrt(b*b-4*c)) / 2.0;
                //if(z<=1e-3) break;
                for (int z = zz - 1; z <= zz + 1; z++)
                {
                    if (z < 1)
                        continue;
                    if (x * x + y * y + z * z + x * y + y * z + z * x == n)
                    {
                        //cout << n << " " << x << " " << y << " " << z << " " << endl;//
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}