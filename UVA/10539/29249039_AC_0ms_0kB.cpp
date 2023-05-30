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
 
#define MAX              (1000001)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > primes;
vector < bool > ifprime(MAX);

void Sieve(){
    ifprime[0] = ifprime[1] = true;
    for(ll i = 4; i < MAX; i += 2) ifprime[i] = true;
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    for(ll i = 0; i < MAX; i++) if(!ifprime[i]) primes.pb(i);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif
    Sieve();

    vector < ll > almostprimes;
    for(ll i = 0; i < primes.size(); i++){
        ll almost = primes[i]*primes[i];
        almostprimes.pb(almost);
        while(almost*primes[i] < 999999999999){
            almostprimes.pb(almost*primes[i]);
            almost = almost*primes[i];
        }
    }
    sort(full(almostprimes));
    ll t; cin >> t;
    while(t--){
        ll l, h; cin >> l >> h;
        ll it1 = lower_bound(full(almostprimes), l) - almostprimes.begin();
        ll it2 = lower_bound(full(almostprimes), h) - almostprimes.begin();
        if(almostprimes[it2] != h) it2--;
        cout << (it2-it1)+1 << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}