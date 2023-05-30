#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remoloweste(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

bool clock(pair < double , double > p1, pair < double , double > p2, pair < double , double > p3){
    double x1 = p1.first, x2 = p2.first, x3 = p3.first;
    double y1 = p1.second, y2 = p2.second, y3 = p3.second;
    return (((y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)) > 0);
}

bool checker(vector < pair < double , double > > points){
    return (clock(points[0], points[1], points[2]) and clock(points[1], points[2], points[3]) and clock(points[2], points[3], points[0]) and clock(points[3], points[0], points[1]));
}

void orientedsorting(vector < pair < double , double > > &points){
    sort(full(points));
    do{
        if(checker(points)) break;
    } while(next_permutation(full(points)));
}

double scope(double x1, double y1, double x2, double y2){
    if(x1 == x2) return abs((y2-y1)/(x2-x1));
    else return (y2-y1)/(x2-x1);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll cn = 0;
    ll t; cin >> t;
    while(t--){
        vector < pair < double , double > > points;
        for(ll i = 0; i < 4; i++){
            ll x, y; cin >> x >> y;
            points.pb(mp(x, y));
        }
        orientedsorting(points);

        double ax = points[0].first, ay = points[0].second;
        double bx = points[1].first, by = points[1].second;
        double cx = points[2].first, cy = points[2].second;
        double dx = points[3].first, dy = points[3].second;

        double ab = sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
        double bc = sqrt(((bx-cx)*(bx-cx))+((by-cy)*(by-cy)));
        double cd = sqrt(((cx-dx)*(cx-dx))+((cy-dy)*(cy-dy)));
        double ad = sqrt(((ax-dx)*(ax-dx))+((ay-dy)*(ay-dy)));
        double bd = sqrt(((bx-dx)*(bx-dx))+((by-dy)*(by-dy)));
        double ac = sqrt(((ax-cx)*(ax-cx))+((ay-cy)*(ay-cy)));

        double scope_ab = scope(ax, ay, bx, by);
        double scope_bc = scope(bx, by, cx, cy);
        double scope_cd = scope(cx, cy, dx, dy);
        double scope_ad = scope(ax, ay, dx, dy);

        bool all90 = false, no90 = false;
        double angle1 = (acos(((ab*ab)+(ad*ad)-(ac*ac))/(2*ab*ad))*180)/PI;
        double angle2 = (acos(((ab*ab)+(bc*bc)-(bd*bd))/(2*ab*bc))*180)/PI;
        double angle3 = (acos(((bc*bc)+(cd*cd)-(ac*ac))/(2*bc*cd))*180)/PI;
        double angle4 = (acos(((ad*ad)+(cd*cd)-(bd*bd))/(2*ad*cd))*180)/PI;
        if((abs(angle1 - 90) <= EPS) and (abs(angle2 - 90) <= EPS) and (abs(angle2 - 90) <= EPS) and (abs(angle2 - 90) <= EPS)) all90 = true;
        if((abs(angle1 - 90) > EPS) and (abs(angle2 - 90) > EPS) and (abs(angle2 - 90) > EPS) and (abs(angle2 - 90) > EPS)) no90 = true;

        bool allequal, oequal;
        if((ab == bc) and (bc == cd) and (cd == ad)) allequal = true;
        else allequal = false;

        if((ab == cd) and (ad == bc) and (ab != ad) and (bc != cd)) oequal = true;
        else oequal = false;

        cout << "Case " << ++cn << ": ";
        if(allequal and all90) cout << "Square" << endl;
        else if(oequal and all90) cout << "Rectangle" << endl;
        else if(allequal and no90) cout << "Rhombus" << endl;
        else if(oequal and no90) cout << "Parallelogram" << endl;
        else if((scope_ab == scope_cd) and (scope_bc != scope_ad)) cout << "Trapezium" << endl;
        else if((scope_ab != scope_cd) and (scope_bc == scope_ad)) cout << "Trapezium" << endl;
        else cout << "Ordinary Quadrilateral" << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}