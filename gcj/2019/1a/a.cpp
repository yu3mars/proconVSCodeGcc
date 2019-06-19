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
        int r, c;
        cin >> r >> c;
        bool swaped = false;
        if (r > c) //r<=c ni suru
        {
            swap(r, c);
            swaped = true;
        }
        if ((r == 2 && c == 4) || c <= 3)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        cout << "POSSIBLE" << endl;
        vector<pii> ans(r * c);
        int diff;
        if (r == 2)
            diff = 3;
        else
            diff = 2;
        for (int rr = 0; rr < r; rr++)
        {
            for (int cc = 0; cc < c; cc++)
            {
                int rrr = rr;
                int ccc;
                int nn;
                if (rr % 2 == 0)
                {
                    ccc = cc;
                    //ccc=(ccc+c-1)%c;
                    nn = rr + r * cc;
                    ans[nn] = make_pair(rrr + 1, ccc + 1);
                }
                else
                {
                    ccc = (cc + diff) % c;
                    //ccc=(ccc+c-1)%c;
                    nn = rr + r * cc;
                    ans[nn] = make_pair(rrr + 1, ccc + 1);
                }
            }
        }
        bool ok;
        ok = true;
        for (int i = 0; i < r * c - 1; i++)
        {
            if (ans[i].first == ans[i + 1].first 
                || ans[i].second == ans[i + 1].second 
                || ans[i].first + ans[i].second == ans[i + 1].first + ans[i + 1].second 
                || ans[i].first - ans[i].second == ans[i + 1].first - ans[i + 1].second)
            {
                ok=false;
               // cout<<"hoge1"<<endl;

            }
        }
        if(ok==false)
        {
            for(int i = 0; i < r*c; i++)
            {
                ans[i]=make_pair(ans[i].first, (ans[i].second+c-2)%c+1);
            }
            
        }

        ok = true;
        for (int i = 0; i < r * c - 1; i++)
        {
            if (ans[i].first == ans[i + 1].first 
                || ans[i].second == ans[i + 1].second 
                || ans[i].first + ans[i].second == ans[i + 1].first + ans[i + 1].second 
                || ans[i].first - ans[i].second == ans[i + 1].first - ans[i + 1].second)
            {
                ok=false;
                //cout<<"hoge2"<<endl;
            }
        }

        if (swaped)
        {
            for (int i = 0; i < r * c; i++)
            {
                cout << ans[i].second << " " << ans[i].first << endl;

            }
        }
        else
        {
            for (int i = 0; i < r * c; i++)
            {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        }
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