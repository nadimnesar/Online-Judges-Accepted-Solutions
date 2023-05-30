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
 
#define MAX              (1e4+8)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

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
    ll n;
    while(cin >> n and n){
        ll i = lower_bound(full(primes), n) - primes.begin();
        //debug2(i, primes[i]);
        ll res = 0;
        for(; i >= 0; i--){
            if(primes[i] == n){
                res++;
                continue;
            }
            if(primes[i] > n) continue;
            ll container = 0;
            for(ll j = i; j >= 0; j--){
                if(primes[j]+container < n){
                    container += primes[j];
                    continue;
                }
                if(container+primes[j] == n){
                    res++;
                    container = 0;
                    break;
                }
                container = 0;
                break;
            }
        }
        cout << res << endl;
    }



#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}