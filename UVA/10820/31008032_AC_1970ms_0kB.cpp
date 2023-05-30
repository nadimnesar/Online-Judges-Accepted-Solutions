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

int ps;
vector < int > prime;
vector < bool > ifprime(MAX);
void Sieve(){
    for(int i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(int j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    prime.pb(2);
    for(int i = 3; i < MAX; i+=2) if(!ifprime[i]) prime.pb(i);
}

int countRelPrime(int n, int m){
    vector < int > factors;
    for(int i = 0; prime[i]*prime[i] <= n; i++){
        if (n%prime[i] == 0){
            factors.pb(prime[i]);
            while(n % prime[i] == 0) n /= prime[i];
        }
    }
    if(n > 1) factors.pb(n);
    n = factors.size();
    int parity[3] = { 0 };
    for(int i = 1; i < (1 << n); i++){
        int mult = 1;
        for (int j = 0; j < n; j++){
            if (i & (1 << j)) mult *= factors[j];
        }
        parity[__builtin_popcount(i)&1] += (m / mult);
    }
    return m - (parity[1] - parity[0]);
}

void solve(){
    int n;
    while(cin >> n and n){
        int res = n;
        for (int i = 2; i <= n; i++) res += countRelPrime(i, n);
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
    ps = prime.size();
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
