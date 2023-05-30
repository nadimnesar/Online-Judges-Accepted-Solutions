#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

vector < ll > primes;
vector < bool > ifprime(maxx);

void Sieve(){
    for(ll i = 3; i*i <= maxx; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < maxx; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < maxx; i+=2) if(!ifprime[i]) primes.pb(i);
}

void solve(){
    ll a, b;
    cin >> a >> b;

    ll ggcd = __gcd(a, b);

    ll res = 0;

    for(ll i = 0; primes[i]*primes[i] <= ggcd; i++){
        if(ggcd%primes[i] == 0){
            while(ggcd%primes[i] == 0) ggcd /= primes[i];
            res++;
        }
    }
    if(ggcd > 2) res++;
    
    cout << res+1 << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    Sieve();
    solve();
    
    return 0;
}