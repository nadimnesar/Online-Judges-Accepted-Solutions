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
 
#define MAX              (1e4+8)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

ll fzero(ll n, ll b){
    ll zeros = 0;
    while(true){
        if(n%b == 0){
            zeros++;
            n /= b;
        }
        else break;
    }
    return zeros;
}

int main(){
 
    //FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll n;
    while(scanf("%lld", &n) != EOF){
        if(n == 0) break;
        ll res = 0;
        for(ll i = 1; i*i <= n; i++){
            if(n%i == 0){
                if(i != 1) res += fzero(n, i);
                if(i*i != n) res += fzero(n, n/i);
            }
        }
        printf("%lld %lld\n", n, res);
    }


#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}