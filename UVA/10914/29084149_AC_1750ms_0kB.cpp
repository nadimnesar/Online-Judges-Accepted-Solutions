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
 
#define MAX              (10000007)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

vector < ll > primes;
vector < bool > ifprime(3164);

void Sieve(){
    ifprime[0] = ifprime[1] = true;
    for(ll i = 4; i < 3164; i += 2) ifprime[i] = true;
    for(ll i = 3; i*i <= 3164; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < 3164; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    for(ll i = 0; i < 3164; i++) if(!ifprime[i]) primes.pb(i);
}

ll sumofdivisors(ll n){
    int sum = 1;
    for (int i = 0; primes[i]*primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            int cnt = 1;
            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }
            sum *= (pow(primes[i], cnt) - 1) / (primes[i] - 1);
        }
    }
    if (n > 1) sum *= (pow(n, 2)-1)/(n-1);
    return sum;
}


vector < ll > ifoddprime(MAX);
void almostsieve(){
    for(ll i = 3; i < MAX; i+=2){
        for(ll j = i+i; j < MAX; j += i){
            if(!(j&1)){
                ifoddprime[j]++;
            }
        }
    }
}

vector < ll > dp(MAX);
void seskahini(){
    dp[1] = 0;
    for(ll i = 2; i < MAX; i++){
        if(ifoddprime[i] == 1) dp[i] = (sumofdivisors(i) - 2*i) + dp[i-1];
        else dp[i] = dp[i-1];
    }
}

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif
    almostsieve();
    Sieve();
    seskahini();

    ll n;
    while(scanf("%lld", &n) and n){
        printf("%lld %lld\n", n, dp[n]);
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}