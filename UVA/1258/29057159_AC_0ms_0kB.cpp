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
 
#define MAX              (1e4+1)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

vector < ll > T(92);

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    T[1] = 1;
    T[2] = 2;
    for(ll i = 3; i < 92; i++){
        T[i] = T[i-1]+T[i-2];
    }
    ll n;
    while(cin >> n){
        ll m = n;
        vector < pair < ll , ll > > data;
        for(ll i = 91; i >= 1; ){
            if(n < 0) break;
            if(T[i] > n){
                i--;
            }
            else{
                data.pb(mp(i, T[i]));
                n -= T[i];
                i -= 2;
            }
        }
        cout << m << endl;
        for(ll i = 0; i < data.size(); i++){
            cout << data[i].first << ' ';
        }
        cout << endl;
        for(ll i = 0; i < data.size(); i++){
            cout << data[i].second << ' ';
        }
        cout << endl;
        cout << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}