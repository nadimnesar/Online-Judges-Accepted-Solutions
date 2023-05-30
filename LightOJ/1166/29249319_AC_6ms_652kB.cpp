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
 
#define MAX              (10000002)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t, cn = 0;
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vector < ll > arr(n);
        for(ll i = 0; i < n; i++) cin >> arr[i];
        ll swp = 0;
        while(arr.size() != 0){
            ll mindex = min_element(full(arr)) - arr.begin();
            ll mini = arr[mindex];
            if(arr[0] == mini) iremove(arr, 0);
            else{
                swap(arr[mindex], arr[0]);
                swp++;
                iremove(arr, 0);
            }
        }
        cout << "Case " << ++cn << ": " << swp << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}