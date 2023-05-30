#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

vector < ll > primes;
vector < bool > ifprime(maxx);

bool check(ll n){
    string s = to_string(n);
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '0') return false;
    }
    while(s.size()){
        reverse(full(s));
        s.pop_back();
        if(s.size() == 0) return true;
        reverse(full(s));
        ll n = 0;
        for(ll i = 0; i < s.size(); i++) n = (n*10) + (s[i]-'0');
        if(!binary_search(full(primes), n)) return false;
    }
    return true;
}

void Sieve(){
    for(ll i = 3; i*i <= maxx; i += 2){
        if(!ifprime[i]){
            for(ll j = i*i; j < maxx; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < maxx; i+=2){
        if(!ifprime[i] and check(i)){
            primes.pb(i);
        }
    }
}

void nadimnesar() {
    ll n;
    cin >> n;
    cout << upper_bound(full(primes), n) - primes.begin() << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    Sieve();

    int t, cn = 0;
    cin >> t;
    while (t--){
        // cout << "Case " << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}