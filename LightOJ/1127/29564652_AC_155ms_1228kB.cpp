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
 
#define MAX              (3037000499)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > left_sum;
vector < ll > right_sum;

void BT_left(vector < ll > data, ll atSum, ll index, ll n, ll w){
    if(index == n){
        left_sum.pb(atSum); return;
    }
    BT_left(data, atSum, index+1, n, w);
    atSum += data[index];
    BT_left(data, atSum, index+1, n, w);
}

void BT_right(vector < ll > data, ll atSum, ll index, ll n, ll w){
    if(index == n){
        right_sum.pb(atSum); return;
    }
    BT_right(data, atSum, index+1, n, w);
    atSum += data[index];
    BT_right(data, atSum, index+1, n, w);
}

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll cn = 0;
    ll t; cin >> t;
    while(t--){
        ll n, w; cin >> n >> w;
        cout << "Case " << ++cn << ": ";
        if(n == 1){
            ll abertemp; cin >> abertemp;
            if(abertemp <= w) cout << 2 << endl;
            else cout << 1 << endl;
            continue;
        }
        vector < ll > left;
        vector < ll > right;
        for(ll i = 0; i < (n/2); i++){
            ll temp; cin >> temp;
            left.pb(temp);
        }
        for(ll i = n/2; i < n; i++){
            ll temp; cin >> temp;
            right.pb(temp);
        }
        BT_left(left, 0, 0, left.size(), w);
        BT_right(right, 0, 0, right.size(), w);
        sort(full(right_sum));
        ll ans = 0;
        for(ll i = 0; i < left_sum.size(); i++){
            if(left_sum[i] > w) continue;
            else ans += upper_bound(full(right_sum), (w - left_sum[i])) - right_sum.begin();
        }
        cout << ans << endl;
        left_sum.clear();
        right_sum.clear();
    }
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}