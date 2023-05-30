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
 
#define MAX              (100001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

bool check(ll a, ll b, ll c){
    if (a + b <= c || a + c <= b || b + c <= a) return false; 
    else return true; 
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t; cin >> t;
    while(t--){
        ll r, g, b, w;
        cin >> r >> g >> b >> w;
        ll odd = 0, even = 0;
        if(r&1) odd++;
        else even++;
        if(g&1) odd++;
        else even++;
        if(b&1) odd++;
        else even++;
        if(w&1) odd++;
        else even++;
        if(r == 0 or g == 0 or b == 0){
            if(odd > 1) cout << "NO" << endl;
            else cout << "YES" << endl;
            continue;
        }
        if(odd){
            if(even){
                if(odd == 2) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
            else cout << "YES" << endl;
        }
        else cout << "YES" << endl;
    }
    

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}