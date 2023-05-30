#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
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
 
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < string > presave(10001);
vector < ll > res(10001);

string multiplication(string a, ll b){
    ll sum = 0;
    string result;
    ll m = 0;
    reverse(full(a));
    for(ll i = 0; a[i] ; i++){
        m = m + b * (a[i]-'0');
        result.pb((m%10)+48);
        sum += m%10;
        m /= 10;
    }
    while(m > 0){
        result.pb((m%10) + 48);
        sum += m%10;
        m /= 10;
    }
    reverse(full(result));
    res[b] = sum;
    return result;
}

void solve(){
    presave[0] = "1";
    res[0] = 1;
    for(ll i = 1; i <= 10000; i++){
        presave[i] = multiplication(presave[i-1], i);

    }
}


int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    solve();
    ll n;
    while(cin >> n){
        n = abs(n);
        cout << res[n] << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}