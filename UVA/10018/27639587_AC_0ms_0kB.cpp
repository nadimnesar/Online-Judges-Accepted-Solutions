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

llu reverseN(llu n){
	llu reversen = 0;
	while(n){
		reversen = reversen*10 + (n%10);
		n /= 10;
	}
	return reversen;
}

bool palindrome(llu n){
	string s1, s2;
	s1 = to_string(n);
	s2 = s1;
	reverse(full(s2));
	if(s1 == s2) return true;
	else return false;
}

int main(){

	fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif


    llu t;
    cin >> t;
    while(t--){
    	llu n, m, cn = 0;
    	cin >> n;
    	while(true){
    		cn++;
    		m = reverseN(n);
    		m = m+n;
    		if(palindrome(m)) break;
    		else n = m;
    	}
    	cout << cn << ' ' << m << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
