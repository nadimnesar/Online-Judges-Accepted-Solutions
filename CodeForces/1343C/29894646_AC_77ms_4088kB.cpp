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
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll positive = 0;
        ll negetive = 0;
        vector < ll > data;
        for(ll i = 0; i < n; i++){
            ll temp; cin >> temp;
            if(temp > 0) positive++;
            else negetive++;
            data.pb(temp);
        }
        if(negetive == 0 or positive == 0){
            cout << *max_element(full(data)) << endl;
            continue;
        }
        ll sum = 0;
        for(ll i = 0; i < n-1; i++){
            if(data[i] > 0 and data[i+1] > 0){
                data[i+1] = max(data[i], data[i+1]);
                data[i] = 0;
            }
            else if(data[i] < 0 and data[i+1] < 0){
                data[i+1] = max(data[i], data[i+1]);
                data[i] = 0;
            }
            else sum += data[i];
        }
        sum += data[n-1];
        cout << sum << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}