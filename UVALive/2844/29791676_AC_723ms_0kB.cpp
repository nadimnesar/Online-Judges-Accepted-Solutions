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

ll ONE;
ll nosto_board[11][11];

bool valid(ll x, ll y){
    if(x < 0 or x > 10) return false;
    if(y < 0 or y > 10) return false;
    if(nosto_board[x][y] == 0) return true;
    return false;
}

void coutONE(){
    ll cnt = 0;
    for(ll i = 0; i < 11; i++){
        for(ll j = 0; j < 11; j++){
            if(nosto_board[i][j] == 1) cnt++;
        }
    }
    ONE = max(cnt, ONE);
}

void BT(ll r, ll c){
    coutONE();
    if(valid(r+2, c-1)){
        nosto_board[r+2][c-1] = 1;
        BT(r+2, c-1);
        nosto_board[r+2][c-1] = 0;
    }
    if(valid(r+2, c+1)){
        nosto_board[r+2][c+1] = 1;
        BT(r+2, c+1);
        nosto_board[r+2][c+1] = 0;
    }
    if(valid(r-2, c-1)){
        nosto_board[r-2][c-1] = 1;
        BT(r-2, c-1);
        nosto_board[r-2][c-1] = 0;
    }
    if(valid(r-2, c+1)){
        nosto_board[r-2][c+1] = 1;
        BT(r-2, c+1);
        nosto_board[r-2][c+1] = 0;
    }
    if(valid(r+1, c-2)){
        nosto_board[r+1][c-2] = 1;
        BT(r+1, c-2);
        nosto_board[r+1][c-2] = 0;
    }
    if(valid(r+1, c+2)){
        nosto_board[r+1][c+2] = 1;
        BT(r+1, c+2);
        nosto_board[r+1][c+2] = 0;
    }
    if(valid(r-1, c-2)){
        nosto_board[r-1][c-2] = 1;
        BT(r-1, c-2);
        nosto_board[r-1][c-2] = 0;
    }
    if(valid(r-1, c+2)){
        nosto_board[r-1][c+2] = 1;
        BT(r-1, c+2);
        nosto_board[r-1][c+2] = 0;
    }
}

int main(){

/*    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif*/

    ll n, cn = 0;
    while(cin >> n and n){
        for(ll i = 0; i < 11; i++){ for(ll j = 0; j < 11; j++){ nosto_board[i][j] = -1; } }
        ll temp;
        ll cnter = 0;
        for(ll i = 0; i < n; i++){
            ll x, y; cin >> x >> y;
            if(i == 0) temp = x;
            for(ll j = x; j < x+y; j++){
                nosto_board[i][j] = 0;
                cnter++;
            }
        }
        nosto_board[0][temp] = 1;
        BT(0, temp);
        cout << "Case " << ++cn << ", ";
        cout << abs(cnter - ONE);
        if(abs(cnter - ONE) == 1) cout << " square can not be reached." << endl;
        else cout << " squares can not be reached." << endl;
        ONE = 0;
    }

/*#ifndef ONLINE_JUDGE
    Runtime;
#endif*/

}