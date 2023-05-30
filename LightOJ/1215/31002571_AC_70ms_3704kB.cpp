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
#define MAX              (2000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

llu binpow(llu n, llu p){
    if(p == 0) return 1;
    llu res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

ll psize;
vector < ll > primes;
vector < bool > ifprime(MAX);

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

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

unordered_map < ll, ll > factors;
unordered_map < ll, ll > extra;

void solve(){
    ll a, b, L;
    cin >> a >> b >> L;

    ll x = lcm(a, b), cx = x, cL = L, limit = sqrtl(x+1.0);



    factors.clear();
    extra.clear();

    for(ll i = 0; primes[i] <= limit; i++){
        if(x%primes[i] == 0){
            ll cnt = 0;
            while(x%primes[i] == 0){
                cnt++;
                x /= primes[i];
            }
            factors[primes[i]] = cnt;
        }
    }
    if(x > 1) factors[x] = 1;

    // for(auto it: factors) debug2(it.first, it.second);

    bool ok = true;
    limit = sqrtl(L+1.0);

    for(ll i = 0; primes[i] <= limit; i++){
        if(L%primes[i] == 0){
            ll cnt = 0;
            while(L%primes[i] == 0){
                cnt++;
                L /= primes[i];
            }
            ll q = factors[primes[i]];
            factors[primes[i]] = cnt;
            if(q > cnt){
                ok = false;
                break;
            }
            else{
                cnt -= q;
                if(cnt != 0) extra[primes[i]] = cnt;
            }
        }
    }
    // debug(L);
    if(L > 1){
        ll q = factors[L];
        factors[L] = 1;
        if(q > 1) ok = false;
        else if(q == 0) extra[L] = 1;
    }

    // for(auto it: factors) debug2(it.first, it.second);

    if(!ok){
        cout << "impossible" << endl;
        return;
    }

    // for(auto it: extra) debug2(it.first, it.second);

    ll res = 1;
    for(auto it: extra){
        if(factors[it.first]) res *= binpow(it.first, factors[it.first]);
        else res *= binpow(it.first, it.second);
    }

    ll LCM = lcm(cx, res);
    if(LCM == cL) cout << res << endl;
    else cout << "impossible" << endl;

}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    sieve();
    psize = primes.size();

    int t; cin >> t;
    int cn = 0;
    while(t--){
        cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
