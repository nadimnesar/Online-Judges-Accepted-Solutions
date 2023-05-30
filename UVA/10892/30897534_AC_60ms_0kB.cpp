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
 
#define MAX              (1000007)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > res(MAX);

int main(){



    ll n;
    while(cin >> n and n){
        if(n == 1){
            cout << n << ' ' << 1 << endl;
            continue;
        }
        ll lcms = 0;
        vector < ll > alldivs;
        for(ll j = 2; j*j <= n; j++){
            if(n%j == 0){
                alldivs.pb(j);
                if(j*j != n) alldivs.pb(n/j);
            }
        }
        ll divsize = alldivs.size();
        lcms += divsize+2;
        for(ll k = 0; k < divsize; k++){
            for(ll j = divsize-1; j > k; j--){
                if(lcm(alldivs[k], alldivs[j]) == n) lcms++;
            }
        }
        cout << n << ' ' << lcms << endl;
    }


 
}