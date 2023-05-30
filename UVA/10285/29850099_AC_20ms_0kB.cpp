#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int 
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

ll feild[105][105];
ll maxi, r, c;

ll dx[] = { 1, -1, 0, 0 };
ll dy[] = { 0, 0, 1, -1 };

bool valid(ll x, ll y, ll i){
    ll n = feild[x][y];
    x = x+dx[i]; y = y+dy[i];
    if(x < 0 or x >= r) return false;
    if(y < 0 or y >= c) return false;
    if(feild[x][y] < n) return true;
    return false;
}

void BT(ll x, ll y, ll at){
    maxi = max(maxi, at);
    for(ll i = 0; i < 4; i++){
        if(valid(x, y, i)) BT(x+dx[i], y+dy[i], at+1);
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t; cin >> t;
    while(t--){
        string name;
        cin >> name >> r >> c;
        for(ll i = 0; i < r; i++){
            for(ll j = 0; j < c; j++){
                cin >> feild[i][j];
            }
        }
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