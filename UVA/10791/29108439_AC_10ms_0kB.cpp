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

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll n, cn  = 0;
    while(cin >> n and n){
        vector < ll > alldivs;
        for(ll j = 1; j*j <= n; j++){
            if(n%j == 0){
                alldivs.pb(j);
                if(j*j != n) alldivs.pb(n/j);
            }
        }
        if(alldivs.size() == 2 or alldivs.size() == 1){
            cout << "Case " << ++cn << ": " << n+1 << endl;
            continue;
        }
        sort(full(alldivs));
        ll lcm = 1;
        vector < ll > nlcm;
        for(ll i = 0; i < alldivs.size(); i++){
            ll newlcm = (alldivs[i]*lcm)/(gcd(alldivs[i], lcm));
            if(newlcm != lcm){
                nlcm.pb(alldivs[i]);
                lcm = newlcm;
            }
        }
        if(nlcm[nlcm.size()-1] == n){
            cout << "Case " << ++cn << ": " << n+1 << endl;
            continue;
        }
        /*for(ll i = 0; i < nlcm.size(); i++){
            cout << nlcm[i] << ' ';
        }
        cout << endl;*/
        ll sum = 0;
        for(ll i = nlcm.size()-1; i >= 0; i--){
            if(nlcm[i] == -1) continue;
            for(ll j = 0; j < i; j++){
                if(nlcm[i]%nlcm[j] == 0){
                    nlcm[j] = -1;
                }
            }
            sum += nlcm[i];
        }
        cout << "Case " << ++cn << ": " << sum << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
