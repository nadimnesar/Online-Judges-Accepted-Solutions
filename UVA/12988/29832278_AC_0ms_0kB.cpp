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

char sudoku[4][4];
bool found;

bool checker(ll &n, ll &r, ll &c){
    for(ll j = 0; j < 4; j++){ if(sudoku[r][j] == char(n+48)) return false; }
    for(ll j = 0; j < 4; j++){ if(sudoku[j][c] == char(n+48)) return false; }
    ll rS, rE, cS, cE;
    if(r == 0 or r == 1){
        if(c == 0 or c == 1){ rS = 0; rE = 1; cS = 0; cE = 1; }
        if(c == 2 or c == 3){ rS = 0; rE = 1; cS = 2; cE = 3; }
    }
    if(r == 2 or r == 3){
        if(c == 0 or c == 1){ rS = 2; rE = 3; cS = 0; cE = 1; }
        if(c == 2 or c == 3){ rS = 2; rE = 3; cS = 2; cE = 3; }
    }
    for(ll i = rS; i <= rE; i++){
        for(ll j = cS; j <= cE; j++){ if(sudoku[i][j] == char(n+48)) return false; }
    }
    return true;
}

void BT(ll x, ll y){
    if(found) return;
    if(y == 4){ x++; y = 0; }
    if(x == 4){
        for(ll i = 0; i < 4; i++){
            for(ll j = 0; j < 4; j++){
                cout << sudoku[i][j];
            }
            cout << endl;
        }
        found = true;
        return;
    }
    if(sudoku[x][y] == '*'){
        for(ll i = 1; i <= 4; i++){
            if(checker(i, x, y)){
                sudoku[x][y] = (char)(i+48);
                BT(x, y+1);
                sudoku[x][y] = '*';
            }
        }
    }
    else BT(x, y+1);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t, cn = 0;
    cin >> t;
    while(t--){
        for(ll i = 0; i < 4; i++){
            for(ll j = 0; j < 4; j++){
                cin >> sudoku[i][j];
            }
        }
        cout << "Case #" << ++cn << ":" << endl;
        found = false;
        BT(0, 0);
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
