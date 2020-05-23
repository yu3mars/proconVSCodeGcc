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


int numofbits(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int h,w,k;
vector<string> s;

int calc(int bit)// bit=1 -> shita de waru
{
    int ans=numofbits(bit);
    vector<int> group(h);
    for (int i = 0; i < h; i++)
    {
        group[i]=i;
    }
    for (int i = 0; i < h-1; i++)
    {
        if(((bit>>i) &1) ==0)
        {
            group[i+1]=group[i];
        }
    }
    
    vector<int> count(h);
    for (int ww = 0; ww < w; ww++)//yoko
    {
        vector<int> tmp(h);
        bool over=false;
        bool impossible = false;
        for (int hh = 0; hh < h; hh++)//tate
        {
            tmp[group[hh]]+=count[hh]+(s[hh][ww]-'0');
            if(tmp[group[hh]]>k) 
            {
                over=true;
                break;
            }
        }
        if(over)
        {
            ans++;
            for (int hh = 0; hh < h; hh++)
            {
                count[hh]=0;
            }
            for (int hh = 0; hh < h; hh++)
            {
                count[group[hh]]+=(s[hh][ww]-'0');
                if(count[group[hh]]>k)
                {
                    impossible=true;
                    return h*w;                    
                }
            }
            
        }
        else
        {
            for (int hh = 0; hh < h; hh++)
            {
                count[hh]=tmp[hh];
            }
        }
    }
    //cout<<bit<<"\t"<<ans<<endl;

    return ans;
}

int main()
{
    int ans=100000;
    cin>>h>>w>>k;
    s.resize(h);
    for (int i = 0; i < h; i++)
    {
        cin>>s[i];
    }
    for (int bit = 0; bit < (1<<h-1); bit++)
    {
        ans=min(ans,calc(bit));
    }
    
    cout<<ans<<endl;
    
    return 0;
}