#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
#define pop              pop_back

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (100000001)
#define MOD              (1000000007)
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

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    Sieve();
    ll n;
    while(cin >> n){
        if(n&1){
            if(n != 1 and !(ifprime[n-2])) cout << n << " is the sum of " << "2" << " and " << (n-2) << "." << endl;
            else cout << n << " is not the sum of two primes!" << endl;
        }
        else{
            ll index = (lower_bound(full(primes), n/2) - primes.begin());
            if(ifprime[n/2]) index--;
            bool found = false;
            for(ll i = index; i >= 0; i--){
                if((!(ifprime[n-primes[i]])) and primes[i] != n-primes[i]){
                    cout << n << " is the sum of " << primes[i] << " and " << n-primes[i] << "." << endl;
                    found = true;
                    break;
                }
            }
            if(!found) cout << n << " is not the sum of two primes!" << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}