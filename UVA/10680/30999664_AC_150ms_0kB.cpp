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
#define MAX              (1000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

llu binpow(llu n, llu p){
    if(p == 0) return 1;
    llu res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

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
    ll temp = 1;
    ll res = 0;
    while(true){
        if(temp*p <= n) temp *= p;
        else break;
        res++;
    }
    return res;
}

void solve(){
    // cout << get_power(1000000, 2) << endl;
    ll n;
    while(cin >> n){
        if(n == 0) break;
        if(n <= 5){
            if(n == 1) cout << 1 << endl;
            else if(n == 2) cout << 2 << endl;
            else if(n == 3) cout << 6 << endl;
            else if(n == 4) cout << 2 << endl;
            else cout << 6 << endl;
            continue;
        }
        ll for2 = 0;
        ll for5 = 0;
        ll res = 1;
        for(ll i = 0; primes[i] <= n; i++){
            ll x = get_power(n, primes[i]);
            if(primes[i] == 2) for2 = x;
            else if(primes[i] == 5) for5 = x;
            else{
                ll y = (ll)binpow(primes[i], x);
                res = ((res%10) * (y%10))%10;
            }
        }
        ll y = (ll)(binpow(2, for2-for5))%10;
        res = ((res%10) * (y%10))%10;
        cout << res << endl;
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
