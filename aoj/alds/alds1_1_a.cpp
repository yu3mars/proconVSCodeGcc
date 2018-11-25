#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

void InsertionSort(vector<int> a, int n)
{
    
    for(int i = 1; i < n; i++)
    {
        int v = a.at(i);
        int j = i-1;
        while(j>=0 && a.at(j)>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;

        
        for(int i = 0; i < a.size(); i++)
        {
            cout << a.at(i);
            if(i!=a.size()-1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
        
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
    {
        cin  >> a.at(i);
    }

    for(int i = 0; i < a.size(); i++)
    {
        cout << a.at(i);
        if(i!=a.size()-1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
    
    InsertionSort(a,n);
 
    return 0;
}