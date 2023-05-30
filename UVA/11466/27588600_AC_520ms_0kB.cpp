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

bool prime(ll n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n&1){
        for(llu i = 3; i*i <= n; i+=2){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    else return false;
}

vector < ll > divisors;

void div(ll n){
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			if(prime(i)) divisors.pb(i);
			if(prime(n/i)){
				divisors.pb(n/i);
				return;
			}
		}
	}
	return;
}


int main(){
 
    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
 
    ll n;
    while(cin >> n and n){
    	n = abs(n);
    	div(n);
    	llu size = divisors.size();
    	if(size == 0) cout << "-1" << endl;
    	else if(divisors[size-1] == n) cout << "-1" << endl;
    	else if(divisors[size-1] == divisors[0]) cout << "-1" << endl;
    	else cout << divisors[size-1] << endl;
    	divisors.clear();
    }
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
