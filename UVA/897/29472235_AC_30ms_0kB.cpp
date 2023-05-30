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
 
#define MAX              (1000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > ans;
vector < bool > ifprime(MAX);
void sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j <= MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
}

bool primality_test(ll n){
    if(n == 1) return false;
    else if(n == 2) return true;
    else if(n%2 == 0) return false;
    else if(!ifprime[n]) return true;
    else return false;
}

void solve(){
    for(ll i = 3; i < 800000; i += 2){
        if(primality_test(i)){
            string str = to_string(i);
            sort(full(str));
            bool ok = true;
            do{
                ll num;
                stringstream ss(str);
                ss >> num;
                if(!primality_test(num)){
                    ok = false;
                    break;
                }
            } while(next_permutation(full(str)));
            if(ok) ans.pb(i);
        }
    }
}

ll digits(ll n){
    return (ll)(log10(n)+1);
}


int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    sieve();
    solve();

    ll n;
    while(cin >> n and n){
        if(n == 1){ cout << 2 << endl; continue; }
        auto it = upper_bound(full(ans), n);
        if(it == ans.end()) cout << 0 << endl;
        else if(ans[it-ans.begin()] > (ll)(pow(10, digits(n)))) cout << 0 << endl;
        else cout << ans[it-ans.begin()] << endl;
    }
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
