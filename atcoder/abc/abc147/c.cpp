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

int bitCount(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}

int log2ceil(int n) {
  --n;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}

int convertBit(int n)
{
    return (1<<n);
}

int main()
{
    int n,ans=0;
    cin>>n;
    vector<int> a(n);
    vector<vector<pii>> xy(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        for (int j = 0; j < a[i]; j++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            xy[i].push_back(make_pair(x,y));
        }
    }
    for (int status = 1; status < (1<<n); status++)
    {
        bool ok=true;
        for (int checkPerson = 0; checkPerson < n; checkPerson++)
        {
            int personBit = convertBit(checkPerson);
            if((status & personBit)==0) continue; //usotsuki no baai
            for (int syogenId = 0; syogenId < a[checkPerson]; syogenId++)
            {
                pii syogen = xy[checkPerson][syogenId];
                int syogenX=syogen.first;
                int syogenY=syogen.second;
                int syogenXBit=convertBit(syogenX);
                int syogenTF=(status & syogenXBit);
                if(syogenTF>0) syogenTF=1;
                if(syogenTF!=syogenY)
                {
                    ok=false;
                    break;
                }
            }
            if(ok==false) break;
        }
        if(ok)
        {
            ans=max(ans, bitCount(status));
        }
    }
    
    
    cout<<ans<<endl;
    return 0;
}