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
 
#define MAX              (100001)
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
    ll low, high;
    while(cin >> low >> high){
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
                if(i+low != 1) segmented.pb(i+low);
            }
        }
        if(segmented.size() <= 1) cout << "There are no adjacent primes." << endl;
        else{
            ll mini = LLONG_MAX, minP1, minP2;
            ll maxi = 0, maxP1, maxP2;
            for(ll i = 0; i < segmented.size()-1; i++){
                ll dif = segmented[i+1]-segmented[i];
                if(dif > maxi){
                    maxP1 = segmented[i];
                    maxP2 = segmented[i+1];
                    maxi = dif;
                }
                if(dif < mini){
                    minP1 = segmented[i];
                    minP2 = segmented[i+1];
                    mini = dif;
                }
            }
            cout << minP1 << ',' << minP2 << " are closest, " << maxP1 << ',' << maxP2 << " are most distant." << endl;
        }
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}