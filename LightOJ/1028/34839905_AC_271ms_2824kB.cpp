#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

vector < ll > primes;
bool ifprime[1000007];
void seive(){
    for(ll i = 3; i*i < 1000007; i++){
        if(!ifprime[i]){
            for(ll j = i+i; j < 1000007; j+= i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < 1000007; i+=2){
        if(!ifprime[i]){
            primes.pb(i);
        }
    }
}

void solve(){
    ll t, cn = 0;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll res = 1;
        for(int i = 0; i < primes.size(); i++){
            if(primes[i]*primes[i] > n) break;
            if(n%primes[i] == 0){
                ll cnt = 1;
                while(n%primes[i] == 0){
                    cnt++;
                    n /= primes[i];
                }
                res *= cnt;
            }
        }
        if(n > 1) res *= 2;
        cout << "Case " << ++cn << ": " << res-1 << endl;
    }
}

int main(){

//    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    seive();
    solve();

    return 0;
}
