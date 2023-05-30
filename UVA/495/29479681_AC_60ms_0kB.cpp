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
 
#define MAX              (3037000499)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

string add(string a,string b){
    string result;
    reverse(full(a));
    reverse(full(b));
    if(a.size() < b.size()) swap(a, b);
    while(b.size() < a.size()) b.pb('0');
    ll i = 0, carry = 0;
    while(a[i]){
        carry = carry + a[i]-48 + b[i]-48;
        result.pb((carry %10) + 48);
        carry = carry / 10;
        i++;
    }
    while(carry > 9){
        result.pb((carry % 10) + 48);
        carry = carry / 10;
    }
    if(carry != 0) result.pb(carry + 48);
    reverse(full(result));
    return result;
}

vector < string > fibonacchi(5001);
void solve(){
    fibonacchi[0] = "0";
    fibonacchi[1] = "1";
    for(ll i = 2; i <= 5000; i++){
        fibonacchi[i] = add(fibonacchi[i-1], fibonacchi[i-2]);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    solve();
    ll n;
    while(cin >> n) cout << "The Fibonacci number for " << n << " is " << fibonacchi[n] << endl;
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
