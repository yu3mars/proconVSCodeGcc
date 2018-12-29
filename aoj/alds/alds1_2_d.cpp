#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int cnt,m=0;
vector<int> a;
vector<int> g;

void InsertionSort(vector<int> b, int n, int g)
{
    
    for(int i = g; i < n; i++)
    {
        int v = a[i];
        int j = i-g;
        while(j>=0 && a[j]>v)
        {
            a[j+g]=a[j];
            j-=g;
            cnt++;
        }
        a[j+g]=v;
    }
}

void ShellSort(vector<int> b, int n)
{    
    for(int i = 1; i <= n; i=i*3+1)
    {
        g.push_back(i);
    }
    m=g.size();
    
    for(int i = m-1; i >= 0; i--)
    {     
        InsertionSort(a,n,g[i]);
    }

    cout<<m<<endl;
    
    for(int i = m - 1; i >= 0; i--)
    {
        cout<<g[i];
        if(i>0)cout<<" ";
        else cout<<endl; 
    }
}

int main()
{
    int n;
    cin>>n;
    cnt=0;
    
    for(int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        a.push_back(num);
    }
    
    ShellSort(a,n);

    cout<<cnt<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}