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
 
#define MAX              (1000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

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

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif
    Sieve();
    ll t; cin >> t;
    while(t--){
        ll low, high; cin >> low >> high;
        if(low > high) swap(low, high);
        vector < ll > segmented;
        vector < bool > area((high-low)+1, true);
        for(ll i = 0; primes[i]*primes[i] <= high; i++){
            ll start = ((low/primes[i])*primes[i]);
            if(start < low) start += primes[i];
            for(ll j = start; j <= high; j += primes[i]){
                if(j == primes[i]) continue;
                area[j-low] = false;
            }
        }
        for(ll i = 0; i < (high-low)+1; i++){
            if(area[i]){
                if(i+low != 1 and i+low != 0){
                    segmented.pb(i+low);
                }
            }
        }
        if(segmented.size() <= 1){
            cout << "No jumping champion" << endl;
            continue;
        }
        if(segmented.size() == 2){
            cout << "The jumping champion is " << segmented[1]-segmented[0] << endl;
            continue;
        }
        ll ans;
        ll maxi = 0;
        ll mini = LLONG_MAX;
        map < ll , ll > feq;
        for(ll i = 0; i < segmented.size()-1; i++){
            feq[segmented[i+1]-segmented[i]]++;
            if(feq[segmented[i+1]-segmented[i]] >= maxi){
                maxi = feq[segmented[i+1]-segmented[i]];
                ans = segmented[i+1]-segmented[i];
            }
        }
        ll cnt = 0;
        for(auto it = feq.begin(); it != feq.end(); it++){
            if(it->second == maxi) cnt++;
        }
        if(cnt > 1) cout << "No jumping champion" << endl;
        else cout << "The jumping champion is " << ans << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}