#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
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

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

struct customHash {
    static uint64_t nadimnesar(uint64_t x) { x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31); }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return nadimnesar(x+FIXED_RANDOM);
    }
};

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

    gp_hash_table < ll, ll, customHash> table;


    string str;
    cin >> str;

    ll n = 0;
    ll k = 0;
    for(ll i = 0; str[i]; i++){
        if(str[i] == '!') k++;
        else n = (n*10) + (str[i]-'0');
    }

    while(n > 0){
        ll m = n;
        for(ll i = 0; primes[i]*primes[i] <= n; i++){
            if(n%primes[i] == 0){
                ll cnt = 0;
                while(n%primes[i] == 0){
                    cnt++;
                    n /= primes[i];
                }
                table[primes[i]] += cnt;
            }
        }
        if(n > 1) table[n]++;
        n = m-k;
    }

    ll res = 1;
    for(auto it: table){
        res *= (it.second+1);
        if(res > 1e18){
            cout << "Infinity" << endl;
            return;
        }
    }

    cout << res << endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Sieve();

    int t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }

    // solve();
    
    return 0;
}