#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pic = pair<int, char>;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};

const int MAX = 100010;
const ll INF = __LONG_LONG_MAX__/3;

int n;
vector<int> G[MAX];
bool visited[MAX];
int prenum[MAX], lowest[MAX], parent[MAX], timer;

void dfs(int current, int prev){
    prenum[current]=lowest[current]=timer;
    timer++;

    visited[current]=true;

    for(int i = 0; i < G[current].size(); i++)
    {
        int next=G[current][i];
        if(visited[next]==false)
        {
            parent[next]=current;
            dfs(next,current);
            lowest[current]=min(lowest[current],lowest[next]);
        }
        else if(next!=prev)
        {
            lowest[current]=min(lowest[current],prenum[next]);            
        }
    }
}

void art_points(){
    timer=1;
    for(int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    dfs(0,-1);
    
    set<int> ap;
    int np=0;
    for(int i = 1; i < n; i++)
    {
        int p=parent[i];
        if(p==0) np++;
        else if(prenum[p]<=lowest[i])
        {
            ap.insert(p);
        }
    }
    if(np>1) ap.insert(0);
    for(auto it = ap.begin(); it != ap.end(); it++)
    {
        cout<<*it<<endl;
    }
    
}

int main(){
    int e;
    cin>>n>>e;
    for(int i = 0; i < e; i++)
    {
        int s,t;
        cin>>s>>t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    art_points();

    return 0;
}