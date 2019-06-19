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

// syaei
Point project(Segment s, Point p){
    Vector base = s.p2-s.p1;
    double r = dot(p-s.p1, base) / base.norm();
    return s.p1 + base*r;
}

// hansya
Point reflect(Segment s, Point p){
    return p + (project(s,p)-p)*2.0;
}

// ccw
int ccw(Point p0, Point p1, Point p2)
{
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS) return 1; //ccw
    if(cross(a,b)<-EPS) return -1; //cw
    if(dot(a,b)<-EPS) return 2; //p2-p0-p1
    if(a.norm()<b.norm()) return -2; //p0-p1-p2
    return 0; //p0-p2-p1
}

// kousa
bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1,p2,p3) * ccw(p1,p2,p4)<=0 &&
        ccw(p3,p4,p1) * ccw(p3,p4,p2)<=0);
}
bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistance(Point p1, Point p2)
{
    return (p1-p2).abs();
}
double getDistanceLP(Line l, Point p){
    return abs(cross(l.p2-l.p1, p-l.p1))/(l.p2-l.p1).abs();
}
double getDistanceSP(Segment s, Point p){
    if(dot(s.p2-s.p1, p-s.p1)<-0.0) return (p-s.p1).abs();
    if(dot(s.p1-s.p2, p-s.p2)<-0.0) return (p-s.p2).abs();
    return getDistanceLP(s,p);
}
double getDistance(Segment s1, Segment s2)
{
    if(intersect(s1,s2)) return 0.0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
        min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}

// region geometry end

int main(){
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    int q;
    cin>>q;
    for(int qq = 0; qq < q; qq++)
    {
        vector<Point> v(4);
        for(int i = 0; i < 4; i++)
        {
            int x,y;
            cin>>x>>y;
            v[i]=Point(x,y);
        }
        Segment s1=Segment(v[0],v[1]);
        Segment s2=Segment(v[2],v[3]);
        cout<<getDistance(s1,s2)<<endl;
    }
    
    return 0;
}