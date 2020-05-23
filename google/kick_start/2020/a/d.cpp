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
        vector<string> s(n);
        vector<ll> diff(n-1),diffBef(n),diffAft(n);
        vector<bool> used(n);
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
        }
        sort(all(s));
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < min(s[i].length() ,s[i+1].length()); j++)
            {
                if(s[i][j]==s[i+1][j]) diff[i]++;
            }
            diffAft[i]=diff[i];
            diffBef[i+1]=diff[i];
        }

        ll ans=0;

        vector<pair<ll,int>> p(n-1);
        for (int i = 0; i < n-1; i++)
        {
            p[i]=make_pair(diff[i],i);
        }
        sort(all(p));
        ll usedCnt=0,pCnt=0;
        while (usedCnt<n && pCnt<n)
        {
            auto bgn=p[pCnt];
            pCnt++;
            if(used[bgn.second]==true) continue;
            used[bgn.second]=true;
            ll bef=bgn.second,aft=bgn.second,cnt=1;
            ll score=s[bef].length();
            while (cnt<k)
            {
                if(diffBef[bef]==0 && diffAft[aft]==0)
                {
                    score=0;
                    break;
                }

                if(diffBef[bef]==0)
                {
                    score=min(score,diffAft[aft]);
                    aft++;
                    cnt++;
                    used[aft]=true;
                    usedCnt++;

                }
                else if(diffAft[aft]==0)
                {
                    score=min(score,diffBef[bef]);
                    bef++;
                    cnt++;
                    used[bef]=true;
                    usedCnt++;
                }
                else
                {
                    if(diffBef[bef]<=diffAft[aft])
                    {
                        score=min(score,diffAft[aft]);
                        aft++;
                        if(used[aft]==false)
                        {
                            cnt++;
                            used[aft]=true;
                            usedCnt++;
                        }
                    }
                    else
                    {
                        score=min(score,diffBef[bef]);
                        bef++;
                        if(used[bef]==false)
                        {
                            cnt++;
                            used[bef]=true;
                            usedCnt++;
                        }
                    }
                }
            }
            ans+=score;
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