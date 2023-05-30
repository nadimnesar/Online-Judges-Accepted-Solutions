#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)

#define bug              cout << "!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
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

map < ll , ll > prefactors[101];

void precalculation(){
    for(ll n = 2; n <= 100; n++){
        ll m = n;
        ll i = 0, ssize = 0;
        while(m != 1){
            if(m%primes[i] == 0){
                m /= primes[i];
                prefactors[n][primes[i]]++;
            }
            else{
                i++;
                if(i == primes.size()) break;
            }
        }
        if(m != 1) prefactors[n][m]++;
    }
}

map < ll , ll > result;

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    Sieve();
    precalculation();
    llu cn = 0, t; cin >> t;
    while(t--){
        ll n; cin >> n;
        for(ll i = 2; i <= n; i++){
            for(auto it: prefactors[i]){
                result[it.first] += it.second;
            }
        }
        cout << "Case " << ++cn << ": " << n << " = ";
        ll sssize = result.size();
        ll j = 0;
        for(auto it: result){
            j++;
            if(j == sssize) cout << it.first << " (" << it.second << ")" << endl;
            else cout << it.first << " (" << it.second << ") * ";
        }
        result.clear();
    }


#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}