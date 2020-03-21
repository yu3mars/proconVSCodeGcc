#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int dp[500050][26];

int main()
{
    m0(dp);

    int n;
    string s;
    cin>>n>>s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[i+1][j]=dp[i][j];
        }
        dp[i+1][s[i]-'a']++;
    }
    
    map<int,vector<int>> mp;
    int qq;
    cin>>qq;
    for (int q = 0; q < qq; q++)
    {
        int kind;
        cin>>kind;
        if(kind==1)
        {
            int ith;
            char chr;
            cin>>ith>>chr;
            ith--;
            char chrNow=s[ith];
            if(chr==chrNow) continue;

            int charNum = chr-'a';
            int charNowNum = chrNow-'a';
            
            if(mp.find(ith)==mp.end())
            {
                vector<int> ls(26);
                ls[charNum]++;
                ls[charNowNum]--;

                mp.emplace(ith,ls);
                
            }
            else
            {
                mp[ith][charNum]++;
                mp[ith][charNowNum]--;
            }
            string chrStr{chr};
            s.replace(ith,ith+1,chrStr);
            
        }
        else //kind == 2
        {
            int l,r;
            cin>>l>>r;
            int cnt[26];
            for (int i = 0; i < 26; i++)
            {
                cnt[i]=dp[r+1]-dp[l];
            }
            auto begin = mp.lower_bound(l);
            auto last = mp.upper_bound(r);
            while (begin != last) {
                for (int i = 0; i < 26; i++)
                {
                    cnt[i]+=begin->second[i];
                }
                
                begin++;
            }
            int ans=0;
            for (int i = 0; i < 26; i++)
            {
                cout<<cnt[i]<<"\t";
                if(cnt[i]>0) ans++;
            }
            cout<<ans<<endl;
        }
        
    }
    
    
    return 0;
}