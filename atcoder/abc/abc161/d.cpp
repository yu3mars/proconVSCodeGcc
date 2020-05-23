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

vector<int> getNext(vector<int> v)
{
    int keta = v.size();
    if(keta==1)
    {
        if(v[0]<9)
        {
            v[0]++;
            return v;
        }
        else
        {
            v[0]=1;
            v.push_back(0);
            return v;
        }
    }
    
    for (int nowKeta = keta - 2; nowKeta >= 0; nowKeta--)
    {
        if(v[nowKeta]>=v[nowKeta+1] && v[nowKeta+1]<9) //xx32, xx33 mitaina
        {
            v[nowKeta+1]++;
            for (int sitanoKeta = nowKeta+2; sitanoKeta < keta; sitanoKeta++)
            {
                v[sitanoKeta]=max(0,v[sitanoKeta-1]-1);
            }
            return v;
        }
    }
    
    if(v[0]<9)
    {
        v[0]++;
        for (int i = 1; i < keta; i++)
        {
            v[i]=max(0,v[i-1]-1);
        }
        
        return v;
    }
    else
    {
        v[0]=1;
        for (int i = 1; i < keta; i++)
        {
            v[i]=0;
        }
        v.push_back(0);
        return v;
    }


}

void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }
    cout<<endl;
}

int main()
{
    ll k;
    cin>>k;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < k; i++)
    {
        v=getNext(v);
//        cout<<i+1<<"\t";
//        printV(v);
    }
    printV(v);
    
    return 0;
}