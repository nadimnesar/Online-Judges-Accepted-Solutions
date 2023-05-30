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

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

double area(double a, double b, double c){
    double s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void solve(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double t_angle = area(a-c, b, d);
    double h = t_angle/((1.0/2.0)*(a-c));
    cout << dot(6) << abs(((a+c)/2.0)*h) << endl;
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