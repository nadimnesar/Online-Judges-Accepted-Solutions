#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (1007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))


vector < ll > prime;
vector < bool > ifprime(MAX);
void Sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    prime.pb(2);
    for(ll i = 3; i < MAX; i+=2) if(!ifprime[i]) prime.pb(i);
}

long long count(long long a[], int n, long long m){
    long long parity[3] = { 0 };
    for (int i = 1; i < (1 << n); i++) {
        long long mult = 1;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                mult *= a[j];
 
        parity[__builtin_popcount(i) & 1] += (m / mult);
    }
    return parity[1] - parity[0];
}

long long countRelPrime(long long n, long long m){
    long long a[20];
    int i = 0, j = 0;
    long long pz = prime.size();
    while (n != 1 && i < pz) {
        if ((long long)prime[i] * (long long)prime[i] > n) break;

        if (n % prime[i] == 0) a[j] = (long long)prime[i], j++;
 
        while (n % prime[i] == 0) n /= prime[i];
        i++;
    }
    if (n != 1) a[j] = n, j++;
    return m - count(a, j, m);
}

void solve(){
    ll n;
    while(cin >> n and n){
        ll res = n;
        for (ll i = 2; i <= n; i++){
            res += countRelPrime(i, n);
        }
        cout << res << endl;
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Sieve();
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
