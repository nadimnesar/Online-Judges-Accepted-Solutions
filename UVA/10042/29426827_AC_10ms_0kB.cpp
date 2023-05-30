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

void balerSieve(){
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

ll sumofdigits(ll n){
    ll sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}


int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    balerSieve();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll j = n+1; ; j++){
            ll valolagena = sumofdigits(j);
            ll janiTLEkhamu = j;
            ll tawhudaikortasi = 0;
            ll cnter = 0;
            for(ll i = 0; primes[i]*primes[i] <= janiTLEkhamu; i++){
                if(janiTLEkhamu%primes[i] == 0){
                    ll primedigitsum = sumofdigits(primes[i]);
                    while(janiTLEkhamu%primes[i] == 0){
                        janiTLEkhamu /= primes[i];
                        tawhudaikortasi += primedigitsum;
                        cnter++;
                    }
                }
            }
            if(cnter == 0) continue;
            if(janiTLEkhamu != 1){
                tawhudaikortasi += sumofdigits(janiTLEkhamu);
            }
            if(tawhudaikortasi == valolagena){
                cout << j << endl;
                //AC_na hoile gd n8!
                break;
            }
        }
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}