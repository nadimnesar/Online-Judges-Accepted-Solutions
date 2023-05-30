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
#define MAX              (1e5+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

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

unordered_map < ll , ll > prefactors[101];

void precalculation(){
    for(ll n = 2; n <= 100; n++){
        ll m = n;
        ll i = 0, ssize = 0;
        while(m != 1){
            if(m%primes[i] == 0){
                m /= primes[i];
                prefactors[n][primes[i]]++;
            }
            else{
                i++;
                if(i == primes.size()) break;
            }
        }
        if(m != 1) prefactors[n][m]++;
    }
}

unordered_map < ll , ll > primefactorial;

void solve(){
    ll n, d;
    while(cin >> n >> d){
        if(n == 0 and d == 0) break;
        if(n == 1){
            if(d == 1) cout << 1 << endl;
            else cout << 0 << endl;
            continue;
        }
        primefactorial.clear();
        for(ll i = 2; i <= n; i++){
            for(auto it: prefactors[i]){
                primefactorial[it.first] += it.second;
            }
        }
        bool ok = true;
        for(ll i = 0; primes[i]*primes[i] <= d; i++){
            if(d%primes[i] == 0){
                ll cnt = 0;
                while(d%primes[i] == 0){
                    cnt++;
                    d /= primes[i];
                }
                if(primefactorial[primes[i]] >= cnt){
                    primefactorial[primes[i]] -= cnt;
                }
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(d > 1){
            if(primefactorial[d] >= 1) primefactorial[d] -= 1;
            else ok = false;
        }
        if(!ok){
            cout << 0 << endl;
            continue;
        }
        ll res = 1;
        for(auto it: primefactorial){
            if(it.second >= 1){
                res *= it.second+1;
            }
            // debug(res);
            // debug2(it.first, it.second);
        }
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

    sieve();
    precalculation();


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