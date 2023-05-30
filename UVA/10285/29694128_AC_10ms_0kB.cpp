#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
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
 
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < ll > temp(105); vector < vector < ll > > feild(105, temp);
ll r, c;
ll maxi;

bool left(ll x, ll y){
    ll n = feild[x][y];
    y++; if(y == c) return false;
    if(feild[x][y] < n) return true;
    else return false;
}

bool right(ll x, ll y){
    ll n = feild[x][y];
    y--; if(y == -1) return false;
    if(feild[x][y] < n) return true;
    else return false;
}

bool below(ll x, ll y){
    ll n = feild[x][y];
    x++; if(x == r) return false;
    if(feild[x][y] < n) return true;
    else return false;
}

bool above(ll x, ll y){
    ll n = feild[x][y];
    x--; if(x == -1) return false;
    if(feild[x][y] < n) return true;
    else return false;
}

void BT(ll x, ll y, ll at){
    maxi = max(maxi, at);
    if(left(x, y)){ BT(x, y+1, at+1); }
    if(right(x, y)){ BT(x, y-1, at+1); }
    if(below(x, y)){ BT(x+1, y, at+1); }
    if(above(x, y)){ BT(x-1, y, at+1); }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t; cin >> t;
    while(t--){
        string name;
        cin >> name >> r >> c;
        for(ll i = 0; i < r; i++){ for(ll j = 0; j < c; j++){ cin >> feild[i][j]; } }
        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                BT(i, j, 1);
            }
        }
        cout << name << ": " << maxi << endl;
        maxi = 0;
    }
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif

}