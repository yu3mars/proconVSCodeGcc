#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main()
{
    string s,ans="";
    cin>>s;
    if(s=="zyxwvutsrqponmlkjihgfedcba")ans="-1";
    else
    {
        int ls[26];
        m0(ls);
        
        for(int i = 0; i < s.size(); i++)
        {
            ls[s[i]-'a']++;
        }
        if(s.size()<26)
        {
            for(int i = 0; i < 26; i++)
            {
                if(ls[i]==0)
                {
                    ans=s+(char)('a'+i);
                    break;
                }
            }
        }
        
        else
        {
            char c='z';
            for(int i = 26 - 1; i > 0; i--)
            {
                if(s[i-1]<s[i])
                {
                    for(int j = 0; j < i-1; j++)
                    {
                        ans+=s[j];
                    }
                    
                    for(int j = i; j < 26; j++)
                    {
                        if(s[i-1]<s[j])
                        {
                            c=min(c,s[j]);
                        }
                    }
                    
                    ans+=c;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}