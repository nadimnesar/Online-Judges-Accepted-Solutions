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
 
#define MAX              (101)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }


vector < ll > primes;
vector < bool > ifprime(MAX);

void sieve(){
    ifprime[2] = true;
    for(ll i = 3; i < MAX; i+=2){
        ifprime[i] = true;
    }
    for(ll i = 3; i*i < MAX; i+=2){
        if(ifprime[i]){
            for(ll j = i*i; j < MAX; j += i){
                ifprime[j] = false;
            }
        }
    }
    for(ll i = 0; i < MAX; i++){
        if(ifprime[i]) primes.push_back(i);
    }
}


int main(){
 
	fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    sieve();
    ll n;
    while(cin >> n and n){
    	vector < ll > result(MAX, 0);

    	for(ll i = n; i >= 1; i--){
    		ll m = i; //prime factorization of m and saving all in result array!
    		for (ll j = 0; primes[j]*primes[j] <= m; j++){
	    		if(m%primes[j] == 0){
	    			ll cnt = 0;
		            while(m%primes[j] == 0){
		                m /= primes[j];
		                cnt++;
		            }
		            result[primes[j]] += cnt;
	    		}
    		}
    		if(m > 1) result[m]++;
    	}
    	remove(result, 0);
    	ll size = result.size();
    	if(n < 10) cout << "  " << n;
    	else if(n < 100) cout << ' ' << n;
    	else cout << n;
    	cout << "! =";

    	ll cnt = 0;
    	for(ll i = 0; i < size; i++){
    		cnt++;
    		if(result[i] < 10) cout << "  " << result[i];
    		else if(result[i] < 100) cout << ' ' << result[i];
    		else cout << result[i];
    		if(cnt == 15 and size > 15){
    			cout << endl << "      ";
    			cnt = 0;
    		}
    	}
    	cout << endl;
    }
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}