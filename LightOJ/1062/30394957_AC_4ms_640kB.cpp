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

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y))) //for sorted array
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000000007)
#define PI               (2*acos(0)) //3.1415926535897932384626(acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

void solve(){
    double x, y, c;
    cin >> x >> y >> c;
    double low = 0.0;
    double high = max(x, y);

    int limit = 100000;

    while(limit--){
        double z = (low+high)/2.0;

        double a = sqrt((x*x) - (z*z));
        double b = sqrt((y*y) - (z*z));

        double cc = (a*b)/(a+b);

        if(abs(cc-c) <= EPS){
            cout << dot(10) << z << endl;
            break;
        }
        else{
            if(cc-c > 0){
                low = z;
            }
            else{
                high = z;
            }
        }
    }
}

int main(){
    FastIO;
    int t, cn = 0; cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }
}