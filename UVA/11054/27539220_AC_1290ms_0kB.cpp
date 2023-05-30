#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
#define pop              pop_back
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }


int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll n;
    while(cin >> n and n){
        vector < pair < ll, ll > > wine;
        vector < pair < ll, ll > > sell;
        ll sellsize = 0;
        for(ll i = 0; i < n; i++){
            ll value;
            cin >> value;
            if(value < 0) {
                sell.pb(mp(value, i));
                sellsize++;
            }
            else wine.pb(mp(value, i));
        }
        ll winesize = n-sellsize;
        ll res = 0;
        for(ll i = 0; i < winesize; i++){
            if(wine[i].first == 0) continue;
            else{
                for(ll j = 0; j < sellsize; j++){
                    if(wine[i].first == 0) break;
                    else if(sell[j].first == 0) continue;
                    else{
                        ll mini = min(wine[i].first, abs(sell[j].first));
                        wine[i].first -= mini;
                        sell[j].first += mini;
                        res += mini * abs(sell[j].second - wine[i].second);
                    }
                }
            }
        }
        cout << res << endl;
    }
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
