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

int n,wmax;
int dp[1010][10010];//item, weight
bool used[1010][10010];

class Item{
public:
    int value,weight;
    Item(){}
    Item(int value, int weight):value(value), weight(weight) {}
};

pair<int, vector<int>> knapsack01(vector<Item> items){
    m0(dp);
    m0(used);
    int maxValue=0;
    vector<int> usedls;
    for(int i = 0; i < n; i++)
    {
        for(int w = 0; w <= wmax; w++)
        {
            dp[i+1][w]=dp[i][w];
            if(items[i].weight>w) continue;
            if(items[i].value+dp[i][w-items[i].weight] > dp[i+1][w])
            {
                dp[i+1][w] = items[i].value+dp[i][w-items[i].weight];
                used[i][w]=true;
            }
        }
    }
    maxValue= dp[n][wmax];
    for(int i = n - 1, w=wmax; i >= 0; i--)
    {
        if(used[i][w])
        {
            usedls.push_back(i);
            w-=items[i].weight;
        }
    }
    return make_pair(maxValue,usedls);
}

int main(){
    m0(dp);
    cin>>n>>wmax;
    vector<Item> items(n);
    for(int i = 0; i < n; i++)
    {
        cin>>items[i].value>>items[i].weight;
    }
    auto ans = knapsack01(items);
    cout<<ans.first<<endl;
    
    return 0;
}