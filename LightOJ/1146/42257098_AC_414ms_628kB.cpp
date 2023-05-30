#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

typedef struct point{
    double x, y;
} point;

double distance(point a, point b){
    double x = (b.x - a.x) * (b.x - a.x);
    double y = (b.y - a.y) * (b.y - a.y);
    return sqrt(x+y);
}

double line_segment(point a, point b, point c, point d, double m1, double m2){
    double x1 = (((distance(a, b) - m1) * a.x) + (m1 * b.x))/distance(a, b);
    double y1 = (((distance(a, b) - m1) * a.y) + (m1 * b.y))/distance(a, b);

    double x2 = (((distance(c, d) - m2) * c.x) + (m2 * d.x))/distance(c, d);
    double y2 = (((distance(c, d) - m2) * c.y) + (m2 * d.y))/distance(c, d);

    point p, q;
    p.x = x1; p.y = y1;
    q.x = x2; q.y = y2;

    return distance(p, q);
    //https://youtu.be/xuqThOk8zPo
}

void solve() {
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    double l1 = 0;
    double r1 = distance(a, b);

    double l2 = 0;
    double r2 = distance(c, d);

    ll limit = 1e4;

    double res = LLONG_MAX;
    while(limit--){

        double m1 = l1 + (r1-l1) / 3.0;
        double m2 = r1 - (r1-l1) / 3.0;

        double m3 = l2 + (r2-l2) / 3.0;
        double m4 = r2 - (r2-l2) / 3.0;

        double d1 = line_segment(a, b, c, d, m1, m3);
        double d2 = line_segment(a, b, c, d, m2, m4);

        res = min({d1, d2, res});
        if(d1 > d2){
            l1 = m1;
            l2 = m3;
        }
        else{
            r1 = m2;
            r2 = m4;
        }
    }

    cout << dot(10) << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }

    return 0;
}