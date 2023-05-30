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
 
#define MAX              (32001)
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
    Sieve();
    vector < vector < ll > > ans(MAX);
    ll j = 0;
    for(ll i = 0; i < primes.size()-2; i++){
        ll dis1 =  primes[i+1] - primes[i];
        ll dis2 = primes[i+2] - primes[i+1];
        if(dis1 != dis2) continue;
        else{
            ans[j].pb(primes[i]);
            ans[j].pb(primes[i+1]);
            ans[j].pb(primes[i+2]);
            ll k = i+3;
            ll preprime = primes[i+2];
            while(k < primes.size()){
                ll dis3 = primes[k] - preprime;
                if(dis3 == dis1){
                    ans[j].pb(primes[k]);
                    preprime = primes[k];
                    k++;
                }
                else{
                    i = k-2;
                    j++;
                    break;
                }
            }
        }
    }
    ll n, m;
    while(cin >> n >> m){
        if(n == 0 and m == 0) break;
        if(n > m) swap(n, m);
        for(ll i = 0; i < j; i++){
            ll cnt = 0;
            for(ll k = 0; k < ans[i].size(); k++){
                if(ans[i][k] >= n and ans[i][k] <= m) cnt++;
            }
            if(cnt == ans[i].size()){
                for(ll k = 0; k < ans[i].size(); k++){
                    if(k == (ans[i].size()-1)) cout << ans[i][k] << endl;
                    else cout << ans[i][k] << ' ';
                }
            }
        }
    }
 
}