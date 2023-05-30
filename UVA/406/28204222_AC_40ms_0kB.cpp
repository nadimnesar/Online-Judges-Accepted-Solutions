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

int primesize;
vector < ll > primes;
vector < bool > ifprime(1001);

void sieve(){
    ifprime[2] = true;
    for(ll i = 3; i < 1001; i+=2){
        ifprime[i] = true;
    }
    for(ll i = 3; i*i < 1001; i+=2){
        if(ifprime[i]){
            for(ll j = i*i; j < 1001; j += i){
                ifprime[j] = false;
            }
        }
    }
    for(ll i = 0; i < 1001; i++){
        if(ifprime[i]) primes.push_back(i);
    }
}

int main(){

	fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    primes.pb(1);
    sieve();
    primesize = primes.size();
    int n, c;
    while(cin >> n >> c){
    	cout << n << ' ' << c << ':';
    	vector < int > primelist;
    	for(int i = 0; i < primesize; i++){
    		if(primes[i] > n) break;
    		else primelist.pb(primes[i]);
    	}
    	int listsize = primelist.size();
    	if(listsize&1) c = 2*c - 1;
    	else c = 2*c;
    	int index = (listsize - c)/2;
    	if(c > listsize){
    		for(int i = 0; i < listsize; i++){
    			cout << ' ' << primelist[i];
    		}
    		cout << endl;
    	}
    	else{
    		for(int i = index; i < index+c; i++){
    			cout << ' ' << primelist[i];
    		}
    		cout << endl;
    	}
    	cout << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}