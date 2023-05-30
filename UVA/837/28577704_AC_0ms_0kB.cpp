#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
#define pop              pop_back

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000007)
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

    ll t; cin >> t;
    bool br = false;
    while(t--){
        if(br) cout << endl;
        else br = true;
        ll films;
        cin >> films;
        vector < double > xaxis;
        vector < pair < double, double > > data;
        vector < double > data_TC;
        for(ll i = 0; i < films; i++){
            double x1, y1, x2, y2, TC;
            cin >> x1 >> y1 >> x2 >> y2 >> TC;
            xaxis.pb(x1);
            xaxis.pb(x2);
            if(x1 > x2) swap(x1, x2);
            data.pb(mp(x1, x2));
            data_TC.pb(TC);
        }
        sort(full(xaxis));
        ll xsize = xaxis.size();
        cout << xsize+1 << endl;
        cout << "-inf " << dot(3) << xaxis[0] << ' ' << "1.000" << endl;
        for(ll i = 1; i < xsize; i++){
            double ans = 1.00;
            for(ll j = 0; j < films; j++){
                if((xaxis[i-1] >= data[j].first) and (xaxis[i] <= data[j].second)){
                    ans *= data_TC[j];
                }
            }
            cout << xaxis[i-1] << ' ' << xaxis[i] << ' ' << ans << endl;
        }
        cout << xaxis[xsize-1] << ' ' << "+inf " << "1.000" << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}