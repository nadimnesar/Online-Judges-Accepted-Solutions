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
 
#define MAX              (1000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > primes;
vector < bool > ifprime(MAX);

void sieve(){
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

    sieve();
    ll n;
    while(cin >> n and n){
        ll dif = 0;
        ll num1 = 0, num2 = 0;
        for(ll i = 0; primes[i] <= (n/2)+1; i++){
            ll temp = n-primes[i];
            if(temp == 2){
                if(abs(primes[i]-2) >= dif){
                    num1 = min(primes[i], (ll)2);
                    num2 = max(primes[i], (ll)2);
                    dif = abs(primes[i] - 2);
                }
            }
            else if((temp&1) and !(ifprime[temp])){
                if(abs(primes[i]-temp) >= dif){
                    num1 = min(primes[i], temp);
                    num2 = max(primes[i], temp);
                    dif = abs(primes[i] - temp);
                }
            }
            else continue;
        }
        cout << n << ":" << endl;
        if(num1+num2 == n) cout << num1 << '+' << num2 << endl;
        else cout << "NO WAY!" << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}