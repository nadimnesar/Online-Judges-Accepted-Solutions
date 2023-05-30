#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll flag[maxx];
ll pre[maxx];

vector < ll > primes;
vector < bool > ifprime(maxx);
void Sieve(){
    for(ll i = 3; i*i <= maxx; i += 2){
        if(!ifprime[i]){
            for(ll j = i*i; j < maxx; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < maxx; i+=2) if(!ifprime[i]) primes.pb(i);
}

void solve() {
    ll n, k;
    cin >> n >> k;

    // cout << pre[n] << endl;

    if(pre[n] >= k) cout << "YES" << endl;
    else cout << "NO" << endl; 
}

bool pcheck(ll n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n&1)) return false;
    if(!ifprime[n]) return true;
    else return false;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }

    memset(flag, 0);
    Sieve();
    
    for(ll i = 1; i < primes.size(); i++){
        ll x = primes[i-1] + primes[i] + 1;

        if(pcheck(x) and x <= 1000) flag[x] = 1;
        // // cout << primes[i-1] << ' ' << primes[i] << ' ' << 1 << ' ' << x << endl;
        // if(x <= 1000) flag[x] = 1;
    }

    // for(ll i = 2; i <= 1000; i++){
    //     cout << flag[i] << endl;
    // }

    pre[0] = flag[0];
    for(ll i = 1; i <= 1000; i++) pre[i] = pre[i-1]+flag[i];

    solve();


    return 0;
}