/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair

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

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll t, cn = 0;
    scanf("%lld", &t);
    while(t--){
        ll n, q;
        scanf("%lld %lld", &n, &q);
        vector < ll > x(n);
        for(ll i = 0; i < n; i++){
            scanf("%lld", &x[i]);
        }
        printf("Case %lld:\n", ++cn);
        while(q--){
            ll a, b;
            scanf("%lld %lld", &a, &b);
            ll index1 = lower_bound(full(x), a) - x.begin();
            ll index2 = lower_bound(full(x), b) - x.begin();

            if(index1 == n or x[index1] > b){
                printf("0\n");
            }
            else{
                if(index2 == n){
                    printf("%lld\n", n-index1);
                }
                else if(x[index2] == b){
                    printf("%lld\n", (index2+1)-index1);
                }
                else{
                    printf("%lld\n", index2-index1);
                }
            }
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
