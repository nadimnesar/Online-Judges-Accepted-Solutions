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
        ll n, w; cin >> n >> w;
        ll feq[26] = {0};
        string str;
        for(ll i = 0; i < n; i++){
            char ch; cin >> ch;
            feq[ch-'a']++;
            str += ch;
        }
        ll dp[n] = {0};
        for(ll i = 0; i < w; i++){
            ll temp; cin >> temp;
            dp[temp-1]++;
        }
        for(ll i = n-2; i >= 0; i--) dp[i] += dp[i+1];
        for(ll i = 0; i < n; i++) feq[str[i]-'a'] += dp[i];
        for(ll i = 0; i < 26; i++){
            if(i == 25) cout << feq[i] << endl;
            else cout << feq[i] << ' ';
        }
    }


#ifndef ONLINE_JUDGE
    Runtime;
#endif

}