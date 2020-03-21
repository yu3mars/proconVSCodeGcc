#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

int main(){
    int n,m;
    cin>>n>>m;
//    vector<int> a(n),b(n),parent(n),isroot(n),pcnt(n);
    vector<int> a(100100),b(100100),parent(100100),isroot(100100),pcnt(100100);
    vector<vector<int>> a2b(100100);
    
    for(int i = 0; i < n-1+m; i++)
    {
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
        a2b[a[i]].push_back(b[i]);
        isroot[b[i]]=-1;
        pcnt[b[i]]++;//oya nannnin iruka
    }
    int root;
    
    for(int i = 0; i < n; i++)
    {
        if(isroot[i]==0)
        {
            root=i;
            parent[i]=0;
        }
        else
        {
            parent[i]=-1;
        }
    }
    
    queue<int> qa;
    qa.push(root);
    while(qa.size()>0)
    {
        int nowpar = qa.front();
        qa.pop();
        
        for(int i = 0; i < a2b[nowpar].size(); i++)
        {
            int nowchi = a2b[nowpar][i];
            pcnt[nowchi]--;
            
            if(pcnt[nowchi]==0)
            {
                parent[nowchi]=nowpar+1;
                qa.push(nowchi);
            }
        }
        
    }
    
    
    for(int i = 0; i < n; i++)
    {
        cout<<parent[i]<<endl;
    }
    

    return 0;
}