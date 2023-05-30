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
 
#define MAX              (100010042)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-6)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

bool primality_test(ll n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n&1){
        for(ll i = 3; i*i <= n; i+=2){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    else return false;
}

vector < ll > dp(10001);

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    dp[0] = 1;
    for(ll i = 1; i <= 10000; i++){
        ll n = (i*i) + (i) + 41;
        if(primality_test(n)) dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
    }
    ll a, b;
    while(cin >> a >> b){
        if(a > b) swap(a, b);
        if(a == 0){
            double have = dp[b];
            double total = b+1;
            cout << dot(2) << (((have/total)*100.00)+EPS) << endl;
        }
        else{
            double have = dp[b] - dp[a-1];
            double total = b - (a-1);
            cout << dot(2) << (((have/total)*100.00)+EPS) << endl;
        }
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}