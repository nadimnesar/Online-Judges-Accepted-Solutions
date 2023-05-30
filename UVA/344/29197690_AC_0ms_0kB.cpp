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
 
#define MAX              (100001)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

struct symbols{
   int i;
   int v;
   int x;
   int l;
   int c;
};

struct symbols dp[101];

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    dp[1].i = 1;
    dp[1].v = 0;
    dp[1].x = 0;
    dp[1].l = 0;
    dp[1].c = 0;

    for(ll j = 2; j <= 100; j++){
        ll num = j, I = 0, V = 0, X = 0, L = 0, C = 0;
again:
        if(num >= 100){
            C++;
            num -= 100;
            goto again;
        }
        else if(num >= 90){
            X++; C++;
            num -= 90;
            goto again;
        }
        else if(num >= 50){
            L++;
            num -= 50;
            goto again;
        }
        else if(num >= 40){
            X++; L++;
            num -= 40;
            goto again;
        }
        else if(num >= 10){
            X++;
            num -= 10;
            goto again;
        }
        else if(num >= 9){
            I++; X++;
            num -= 9;
            goto again;
        }
        else if(num >= 5){
            V++;
            num -= 5;
            goto again;
        }
        else if(num >= 4){
            I++; V++;
            num -= 4;
            goto again;
        }
        else if(num >= 1){
            I++;
            num -= 1;
            goto again;
        }
        else{
            dp[j].i = dp[j-1].i + I;
            dp[j].v = dp[j-1].v + V;
            dp[j].x = dp[j-1].x + X;
            dp[j].l = dp[j-1].l + L;
            dp[j].c = dp[j-1].c + C;
        }
    }
    
    ll n;
    while(cin >> n and n){
        cout << n << ": " << dp[n].i << " i" << ", ";
        cout << dp[n].v << " v" << ", ";
        cout << dp[n].x << " x" << ", ";
        cout << dp[n].l << " l" << ", ";
        cout << dp[n].c << " c" << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
