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
 
#define MAX              (2e3+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

ll dp[2000010];
ll depth[2000010];
ll phi[2000010];

int main(){
 
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    depth[1] = 0;
    dp[1] = 0;
    for(ll i = 1; i <= 2000000; i++) phi[i] = i;
    for(ll i = 2; i <= 2000000; i++){
        if(phi[i] == i){
            for(ll j = i; j <= 2000000; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    for(ll i = 2; i <= 2000000; i++){
        depth[i] = 1+depth[phi[i]];
        dp[i] = depth[i]+dp[i-1];
    }
    
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll m, n;
        scanf("%lld %lld", &m, &n);
        cout << dp[n]-dp[m-1] << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}