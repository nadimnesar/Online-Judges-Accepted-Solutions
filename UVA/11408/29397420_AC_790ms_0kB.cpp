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
 
#define MAX              (5000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > primes;
vector < bool > ifprime(MAX);
vector < pair < ll, ll > > primefactors(MAX);
vector < ll > dp(MAX);

void sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < MAX; i+=2) if(!ifprime[i]) primes.pb(i);
}

void solve(){
    for(ll i = 0; primes[i]*primes[i] <= MAX; i++){
        for(ll j = primes[i]; j < MAX; j += primes[i]){
            if(primefactors[j].first == 0) primefactors[j].first = j;
            ll target = primefactors[j].first;
            bool ok = false;
            while(target%primes[i] == 0){
                target /= primes[i];
                ok = true;
            }
            primefactors[j].first = target;
            if(ok) primefactors[j].second += primes[i];
        }
    }
    dp[0] = 0;
    dp[1] = 0;
    for(ll i = 2; i < MAX; i++){
        if(primefactors[i].first != 1) primefactors[i].second += primefactors[i].first;
        if(primefactors[i].second == 0) primefactors[i].second += i;
        if(primefactors[i].second == 2) dp[i] = dp[i-1]+1; 
        else if(!(ifprime[primefactors[i].second])){
            if(primefactors[i].second&1) dp[i] = dp[i-1]+1;
            else dp[i] = dp[i-1];
        }
        else dp[i] = dp[i-1];
    }
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    sieve();
    solve();
    ll a, b;
    while(cin >> a and a){
        cin >> b;
        if(a > b) swap(a, b);
        cout << dp[b] - dp[a-1] << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}