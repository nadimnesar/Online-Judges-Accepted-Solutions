#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout << "!***!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl

#define full(x)          x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define iremove(x, y)    x.erase(x.begin() + y)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y))) //for sorted array
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (107)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

ll fact[14] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800 };

void solve(){
    ll n;
    while(scanf("%lld", &n) != EOF){
        if(n < 0){
            /*
            We know,
                    F(n) = n * F(n-1)
            then,
                    F(0) = 0 * F(0-1)
                    or, F(0) = 0 * F(-1)
                    or, F(-1) = F(0)/0 = +INFINITY
            Based on this logic,
                    F(-1) = -1 * F(-2)
                    or, F(-2) = F(-1)/-1
                    or, F(-2) = +INFINITY/-1
                    or, F(-2) = -INFINITY
            again,
                    F(-2) = -2 * F(-3)
                    or, F(-3) = F(-2)/-2
                    or, F(-3) = -INFINITY/-2
                    or, F(-3) = +INFINITY
            */

            n = abs(n);
            if(n&1){
                printf("Overflow!\n");
            }
            else printf("Underflow!\n");
        }
        else{
            if(n <= 7){
                printf("Underflow!\n");
            }
            else if(n <= 13){
                printf("%lld\n", fact[n]);
            }
            else printf("Overflow!\n");
        }
    }
}

int main(){
    solve();
}