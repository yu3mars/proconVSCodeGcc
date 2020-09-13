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

static const int MAX=200005;
multiset<int> highest;
multiset<int> kinder[MAX];

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n),b(n),c(q),d(q);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    for (int i = 0; i < q; i++)
    {
        cin>>c[i]>>d[i];
        c[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        kinder[b[i]].insert(a[i]);
        //cout<<"kinder_"<<b[i]<<" "<<a[i]<<endl;
    }

    for (int i = 0; i < MAX; i++)
    {
        if(kinder[i].size()>0)
        {
            int val = *(kinder[i].rbegin());

            //cout<<"kinder "<<i<<"\t"<<val<<endl;//
            highest.insert(val);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int child = c[i];
        int from = b[child];
        int to = d[i];
        int rate = a[child];
        //cout<<"child \t"<<child<<endl;
        //cout<<"rate \t"<<rate<<endl;

        // moto wo koushin
        //cout<<"from_erase \t"<<*kinder[from].rbegin()<<endl;//
        highest.erase(highest.find(*kinder[from].rbegin()));
        kinder[from].erase(kinder[from].find(rate));
        //cout<<"a "<<kinder[from].size()<<endl;//
        if(kinder[from].size()>0)
        {
            //cout<<"from_insert \t"<<*(kinder[from].rbegin())<<endl;//
            highest.insert(*kinder[from].rbegin());
        }

        // ato wo koushin
        if(kinder[to].size()>0)
        {
            //cout<<"to_erase \t"<<*kinder[to].rbegin()<<endl;//
            highest.erase(highest.find(*kinder[to].rbegin()));
        }
        kinder[to].insert(rate);
        highest.insert(*kinder[to].rbegin());
        //cout<<"to_insert \t"<<*(kinder[to].rbegin())<<endl;//

        b[child]=to;

        cout<<*highest.begin()<<endl;
    }
    
    return 0;
}