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
 
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > answers(MAX);
vector < ll > allfactors(MAX);
vector < ll > primes;
vector < bool > ifprime(10001);

void sieve(){
    ifprime[2] = true;
    for(ll i = 3; i < 10001; i+=2){
        ifprime[i] = true;
    }
    for(ll i = 3; i*i < 10001; i+=2){
        if(ifprime[i]){
            for(ll j = i*i; j < 10001; j += i){
                ifprime[j] = false;
            }
        }
    }
    for(ll i = 0; i < 10001; i++){
        if(ifprime[i]) primes.push_back(i);
    }
}


int main(){
 
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    sieve();
    for(ll i = 2; i <= 1000000; i++){
    	ll result = 0;
    	ll m = i;
    	for (ll j = 0; primes[j]*primes[j] <= m; j++){
	    	if(m%primes[j] == 0){
	    		ll cnt = 0;
	    		while(m%primes[j] == 0){
	    			m /= primes[j];
	    			cnt++;
	    		}
	    		result += cnt;
	    	}
    	}
    	if(m > 1) result++;
    	allfactors[i] = result;
    	answers[i] = answers[i-1] + allfactors[i];
    }

    ll n;
    while(scanf("%lld", &n) != EOF){
    	printf("%lld\n", answers[n]);
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}