#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (100000)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

//Learn how to find exponent of a prime number in n!

vector < ll > primes;
vector < bool > ifprime(MAX);

void Sieve(){
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

ll get_power(ll n, ll p){
    ll res = 0;
    for(ll i = p; i <= n; i *= p) res += n/i;
    return res;
}

void solve(){
    ll n, m;
    while(cin >> n >> m){
        int k = m;
        bool ok = true;
        for(ll i = 0; primes[i]*primes[i] <= m; i++){
            if(m%primes[i] == 0){
                ll cnt = 0;
                while(m%primes[i] == 0){
                    m /= primes[i];
                    cnt++;
                }
                // debug2(primes[i], cnt);
                if(get_power(n, primes[i]) < cnt){
                    ok = false;
                    break;
                }
            }
        }
        if(m > 1){
            // debug2(m, 1);
            if(get_power(n, m) < 1) ok = false;
        }
        if(ok) cout << k << " divides " << n << '!' << endl;
        else cout << k << " does not divide " << n << '!' << endl;
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Sieve();
    // debug(primes.size());

    // ll t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}