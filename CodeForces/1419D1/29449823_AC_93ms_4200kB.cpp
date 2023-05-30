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

    
    ll n;
    cin >> n;
    vector < ll > data, copy;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        data.pb(temp);
        copy.pb(temp);
    }
    sort(full(data), greater < int >());
    sort(full(copy));
    vector < ll > ans;
    ll i = 0, j = 0;
    bool active = true;
    while(ans.size() != n){
        if(active) ans.pb(data[i++]);
        else ans.pb(copy[j++]);
        active = !active;
    }
    if(n&1) cout << n/2 << endl;
    else cout << (n/2)-1 << endl;
    for(ll i = 0; i < n; i++){
        if(i == n-1) cout << ans[i] << endl;
        else cout << ans[i] << ' ';
    }
    

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}