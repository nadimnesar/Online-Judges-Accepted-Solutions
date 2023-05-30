#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair
 
#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define EPS              (1e-7)
#define MAX              (100000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

int main(){
 
    FastIO;
/*#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif*/

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector < pair < double, double > > data;
        vector < ll > dp(n+1);
        for(ll i = 0; i < n; i++){
            double x, y; cin >> x >> y;
            data.pb({x, y});
            dp[i] = 1;
        }
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < i; j++){
                if(data[i].first > data[j].first and data[i].second < data[j].second){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        ll res = 1;
        for(ll i = 0; i < n; i++){
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
 
/*#ifndef ONLINE_JUDGE
    Runtime;
#endif*/

}