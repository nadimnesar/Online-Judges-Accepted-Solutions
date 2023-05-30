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
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)        
 
#define EPS              (1e-1)
#define MAX              (1000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

ll arr[MAX];

ll sumofdivisors(ll a, ll b){
	ll limit = sqrt(b);
	while((limit+1)*(limit+1) <= b) limit++;
	for(ll i = 1; i <= limit; i++){
		ll start = ((a/i)*i); if(start < a) start += i;
		for(ll j = start; j <= b; j += i){
			arr[j-a] += i;
			if(j/i > limit) arr[j-a] += j/i;
		}
	}
	ll res = 0;
	for(ll i = a; i <= b; i++) res += arr[i-a];
	return res;
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll a, b; cin >> a >> b;
    cout << sumofdivisors(a, b)*1LL << endl;

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}