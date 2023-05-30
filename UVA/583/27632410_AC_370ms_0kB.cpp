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
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll totalprimes = 0;
    vector < ll > primes;
    vector < bool > ifprime(46341, true);
    for(ll p = 2; p*p < 46341; p++){
        if(ifprime[p]){
            for(ll i = p*p; i < 46341; i += p){
            	ifprime[i] = false;
            }
        }
    }
    for (ll p = 2; p < 46341; p++){
        if (ifprime[p]){
        	primes.push_back(p);
        	totalprimes++;
        }
    }

    ll n;
    while(cin >> n and n){
    	ll m = abs(n);
    	vector < ll > data;
    	ll i = 0, size = 0;
    	while(m != 1){
    		if(m%primes[i] == 0){
    			m /= primes[i];
    			data.pb(primes[i]); size++;
    		}
    		else{
    			i++;
    			if(i == totalprimes) break;
    		}
    	}
    	if(m != 1){
    		data.pb(m); size++;
    	}
    	ll totalprint = 0;
    	cout << n << " = ";
    	if(n < 0) cout << "-1 x ";
    	for(ll i = 0; i < size; i++){
    		if(i == size-1){
    			cout << data[i] << endl;
    			totalprint++;
    		}
    		else{
    			cout << data[i] << " x ";
    			totalprint++;
    		}
    	}
    	if(totalprint == 0) cout << endl;
    }
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
