#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout << "!***!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (0.0000001)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

double slope(double x1, double y1, double x2, double y2){
    if(abs(x1-x2) <= EPS) return INFINITY;
    if(abs(y1-y2) <= EPS) return 0;
    return (y2-y1)/(x2-x1);
}

double clock(double x1, double y1, double x2, double y2, double x3, double y3){
    return (((y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)) > EPS);    //slope of (p1, p2) > slope of (p2, p3)
}

double dis(double x1, double y1, double x2, double y2){
    double x = x2 - x1, y = y2 - y1;
    return sqrt((x * x) + (y * y));
}

bool oriention(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    return (clock(x1, y1, x2, y2, x3, y3) and clock(x2, y2, x3, y3, x4, y4) and clock(x3, y3, x4, y4, x1, y1) and clock(x4, y4, x1, y1, x2, y2));
}

void solve(){
    vector < pair < double, double > > points;
    for(int i = 0; i < 4; i++){
        double x, y; cin >> x >> y;
        points.pb(mp(x, y));
    }
    //oriented sort
    sort(full(points));
    do{
        if(oriention(points[0].first, points[0].second, points[1].first, points[1].second, points[2].first, points[2].second, points[3].first, points[3].second)) break;
    }
    while(next_permutation(full(points)));
    
    double ax = points[0].first, ay = points[0].second;
    double bx = points[1].first, by = points[1].second;
    double cx = points[2].first, cy = points[2].second;
    double dx = points[3].first, dy = points[3].second;

    double ab = dis(ax, ay, bx, by);
    double ac = dis(ax, ay, cx, cy);
    double ad = dis(ax, ay, dx, dy);
    double bc = dis(bx, by, cx, cy);
    double bd = dis(bx, by, dx, dy);
    double cd = dis(cx, cy, dx, dy);

    // debug2(ax, ay);
    // debug2(bx, by);
    // debug2(cx, cy);
    // debug2(dx, dy);

    double angle1 = (acos(((ab*ab)+(ad*ad)-(ac*ac))/(2*ab*ad))*180)/PI;
    double angle2 = (acos(((ab*ab)+(bc*bc)-(bd*bd))/(2*ab*bc))*180)/PI;
    double angle3 = (acos(((bc*bc)+(cd*cd)-(ac*ac))/(2*bc*cd))*180)/PI;
    double angle4 = (acos(((ad*ad)+(cd*cd)-(bd*bd))/(2*ad*cd))*180)/PI;

    bool all90 = false, no90 = false;
    if((abs(angle1 - 90) <= EPS) and (abs(angle2 - 90) <= EPS) and (abs(angle2 - 90) <= EPS) and (abs(angle2 - 90) <= EPS)) all90 = true;
    if((abs(angle1 - 90) > EPS) and (abs(angle2 - 90) > EPS) and (abs(angle2 - 90) > EPS) and (abs(angle2 - 90) > EPS)) no90 = true;

    if(ab == bc and bc == cd and cd == ad){
        if(all90){
            cout << "Square" << endl;
            return;
        }
        if(no90){
            cout << "Rhombus" << endl;
            return;
        }
    }
    if(ab == cd and ad == bc){
        if(all90){
            cout << "Rectangle" << endl;
            return;
        }
        if(no90){
            cout << "Parallelogram" << endl;
            return;
        }
    }
    
    double slope_ad = slope(ax, ay, dx, dy);
    double slope_bc = slope(bx, by, cx, cy);
    double slope_ab = slope(ax, ay, bx, by);
    double slope_cd = slope(cx, cy, dx, dy);

    if(slope_ad == slope_bc and slope_ab != slope_cd) cout << "Trapezium" << endl;
    else if(slope_ad != slope_bc and slope_ab == slope_cd) cout << "Trapezium" << endl;
    else cout << "Ordinary Quadrilateral" << endl;

}

int main(){

    FastIO;
    ll c_n = 0;
    ll t; cin >> t;
    while(t--){
        cout << "Case " << ++c_n << ": ";
        //cout << "Case " << ++c_n << ":" << endl;
        solve();
    }
}