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
#define MAX              (1000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

vector < bool > ifprime(MAX);

void seive(){
	for(ll i = 3; i*i <= MAX; i+=2){
		for(ll j = i+i; j <= MAX; j+= i){
			ifprime[j] = true;
		}
	}
}

bool prlimdromeprimecheck(ll n){
	if(n == 1) return true;
	else if(n == 2) return true;
	else if(!(n&1)) return false;
	else if(!ifprime[n]){
		vector < ll > num1, num2;
		ll x = n;
		while(x){
			num1.pb(x%10);
			num2.pb(x%10);
			x /= 10;
		}
		reverse(full(num1));
		if(num1 == num2) return true;
		else return false;
	}
	else return false;
}

/*ll powerofn(ll n, ll k){
	ll res = 0;
	for()
}*/

int main(){

#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    
    string str;
    while(cin >> str){
    	if(str == "0") break;
    	ll res = 0;
    	ll len = str.size();
    	for(ll i = 0; str[i]; i++){
    		res += (str[i]-48)*((pow(2, len-i))-1);
    		//cout << (str[i]-48) << " * " << "2^ " << len-i << "+ ";
    	}
    	//cout << endl;
    	cout << res << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
