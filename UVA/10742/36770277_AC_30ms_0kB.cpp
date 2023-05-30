#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

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

void solve() {
    ll n, cn = 0;
    while(cin >> n and n){
        ll res = 0;
        for(ll i = 0; primes[i] < n; i++){

            auto it = lower_bound(primes.begin()+i+1, primes.end(), n - primes[i]);
            if(it == primes .end()) break;

            ll idx = it - primes.begin();

            if(primes[idx] > n - primes[i]) idx--;

            res += idx-i;
        }
        cout << "Case " << ++cn << ": ";
        cout << res << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Sieve();

    /*int t, cn = 0;
    cin >> t;
    while(t--){
        // cout << "Case #" << ++cn << ": ";
        solve();
    }*/

    solve();

    return 0;
}