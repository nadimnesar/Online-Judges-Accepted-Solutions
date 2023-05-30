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

set < vector < vector < ll > > > ans;

ll dx[] = { 1, -1, 0, 0 };
ll dy[] = { 0, 0, 1, -1 };

ll n;
char area[10][10];
ll flag[10][10];

bool valid(ll r, ll c){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= n) return false;
    if(flag[r][c]) return false;
    if(area[r][c] == '.') return false;
    return true;
}

void BT(ll x, ll y, ll emeralds){
    if(emeralds == 8){
        vector < vector < ll > > data(n);
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                data[i].pb(flag[i][j]);
            }
        }
        ans.insert(data);
        return;
    }
    for(ll i = 0; i < 4; i++){
        ll p = x + dx[i], q = y + dy[i];
        if(valid(p, q)){
            flag[p][q] = 1;
            if(area[p][q] == 'X') BT(p, q, emeralds+1);
            else BT(p, q, emeralds);
            flag[p][q] = 0;
        }
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t; cin >> t;
    while(t--){
        cin >> n;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                cin >> area[i][j];
            }
        }
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                memset(flag, 0, sizeof(flag));
                if(area[i][j] == 'X'){
                    flag[i][j] = 1;
                    BT(i, j, 1);
                }
                else BT(i, j, 0);
            }
        }
        cout << ans.size() << endl;
        ans.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}