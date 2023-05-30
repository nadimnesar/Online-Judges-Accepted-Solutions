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

    ll n, m;
    while(cin >> n >> m and n and m){
        vector < ll > heads(n);
        for(ll i = 0; i < n; i++){
            cin >> heads[i];
        }
        vector < ll > heights(m);
        for(ll i = 0; i < m; i++){
            cin >> heights[i];
        }
        sort(full(heights));

        ll ans = 0;
        ll count = 0;
        for(ll i = 0; i < n; i++){
            auto it = lower_bound(full(heights), heads[i]);
            if(it - heights.begin() < heights.size()){
                ans += heights[it - heights.begin()];
                iremove(heights, (it-heights.begin()));
                count++;
            }
        }
        if(count == n) cout << ans << endl;
        else cout << "Loowater is doomed!" << endl;
    }
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
