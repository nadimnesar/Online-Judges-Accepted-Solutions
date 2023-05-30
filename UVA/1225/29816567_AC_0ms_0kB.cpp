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
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))

#define Freopen          freopen("input.txt", "r", stdin); freopen("Output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }



int main(){

#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t; cin >> t;
    while(t--){
    	ll n; cin >> n;
    	ll feq[10] = {0};
    	for(ll i = 1; i <= n; i++){
    		ll x = i;
    		while(x){
    			feq[x%10]++;
    			x /= 10;
    		}
    	}
    	for(ll i = 0; i < 10; i++){
    		if(i == 9) cout << feq[i] << endl;
    		else cout << feq[i] << ' ';
    	}
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}