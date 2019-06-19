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

//region geometry begin

static const double EPS = (1e-10);
double equals(double a, double b) {return (fabs((a)-(b))<EPS);}

class Point{
public:
    double x,y;

    Point(double x=0, double y=0):x(x),y(y){}

    Point operator + (Point p) {return Point(x+p.x, y+p.y);}
    Point operator - (Point p) {return Point(x-p.x, y-p.y);}
    Point operator * (double a) {return Point(x*a, y*a);}
    Point operator / (double a) {return Point(x/a, y/a);}

    double abs() {return sqrt(norm());}
    double norm() {return x*x+y*y;}

    bool operator < (const Point &p) const{
        return x!=p.x? x<p.x : y<=p.y;
    }

    bool operator == (const Point &p) const{
        return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
    }
};
typedef Point Vector;

//senbun
class Segment{
public:
    Point p1,p2;
    Segment(Point p1=Point(), Point p2=Point()):p1(p1),p2(p2){}
};
//tyokusen
typedef Segment Line;

class Circle{
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r=0.0):c(c),r(r){}
};

//takakkei
typedef vector<Point> Polygon;

//naiseki
double dot(Vector a, Vector b){
    return a.x*b.x+a.y*b.y;
}

//gaiseki
double cross(Vector a, Vector b){
    return a.x*b.y-a.y*b.x;
}

//tyokkou
bool isOrthogonal(Vector a, Vector b)
{
    return equals(dot(a,b), 0.0);
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2)
{
    return equals(dot(a1-a2, b1-b2), 0.0);
}
bool isOrthogonal(Segment a, Segment b)
{
    return equals(dot(a.p2-a.p1,b.p2-b.p1), 0.0);
}

//heikou
bool isParallel(Vector a, Vector b)
{
    return equals(cross(a,b), 0.0);
}
bool isParallel(Point a1, Point a2, Point b1, Point b2)
{
    return equals(cross(a1-a2, b1-b2), 0.0);
}
bool isParallel(Segment a, Segment b)
{
    return equals(cross(a.p2-a.p1,b.p2-b.p1), 0.0);
}


// region geometry end

int main(){
    int q;
    cin>>q;
    for(int qq = 0; qq < q; qq++)
    {
        vector<Point> v(4);
        for(int i = 0; i < 4; i++)
        {
            double x,y;
            cin>>x>>y;
            v[i]=Point(x,y);
        }
        Segment s1 = Segment(v[0],v[1]);
        Segment s2 = Segment(v[2],v[3]);
        if(isParallel(s1,s2)) cout<<2<<endl;
        else if(isOrthogonal(s1,s2)) cout<<1<<endl;
        else cout<<0<<endl;
    }
    
    return 0;
}