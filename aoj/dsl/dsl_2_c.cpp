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

class Node{
    public:
    int location;
    int p,l,r;
    Node(){}
};

class Point{
    public:
    int id,x,y;
    Point(){}
    Point(int id,int x,int y): id(id),x(x),y(y) {}
    bool operator < (const Point &p) const {
        return id < p.id;
    }

    void print(){
        printf("%d\n", id);
    }
};

static const int MAX = 1000000;
static const int NIL = -1;

int n;
Point P[MAX];
Node T[MAX];
int np;

bool lessX(Point p1, Point p2) {
    return p1.x<p2.x;
}
bool lessY(Point p1, Point p2) {
    return p1.y<p2.y;
}

int makeKDTree(int l,int r, int depth)
{
    if(!(l<r)) return NIL;
    int mid = (l+r)/2;
    int t=np;
    np++;
    if(depth%2==0)
    {
        sort(P+l, P+r, lessX);
    }
    else
    {
        sort(P+l, P+r, lessY);        
    }
    T[t].location=mid;
    T[t].l=makeKDTree(l,mid,depth+1);
    T[t].r=makeKDTree(mid+1,r,depth+1);
    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans)
{
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if(sx<=x && x<=tx && sy<=y && y<=ty)
    {
        ans.push_back(P[T[v].location]);
    }
    if(depth%2==0)
    {
        if(T[v].l!=NIL)
        {
            if(sx<=x) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
        }
        if(T[v].r!=NIL)
        {
            if(x<=tx) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
        }
    }
    else
    {
        if(T[v].l!=NIL)
        {
            if(sy<=y) find(T[v].l,sx,tx,sy,ty,depth+1,ans);
        }
        if(T[v].r!=NIL)
        {
            if(y<=ty) find(T[v].r,sx,tx,sy,ty,depth+1,ans);
        }        
    }
    
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        P[i]=Point(i,x,y);
        T[i].l=T[i].r=T[i].p=NIL;
    }

    np=0;

    int root = makeKDTree(0,n,0);

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int sx,tx,sy,ty;
        vector<Point> ans;
        scanf("%d %d %d %d",&sx,&tx,&sy,&ty);
        find(root,sx,tx,sy,ty,0,ans);
        sort(all(ans));
        for(int j = 0; j < ans.size(); j++)
        {
            ans[j].print();
        }
        printf("\n");
    }
    
    return 0;
}