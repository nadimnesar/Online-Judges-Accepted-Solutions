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

vector < string > sudoku;
bool found;

bool checker(ll &num, ll &row, ll &column){
    bool ok = true;
    for(ll j = 0; j < 4; j++){ if(sudoku[row][j] == char(num+48)){ ok = false; break; } }
    for(ll j = 0; j < 4; j++){ if(sudoku[j][column] == char(num+48)){ ok = false; break; } }
    ll rowS, rowE, columnS, columnE;
    if(row == 0 or row == 1){
        if(column == 0 or column == 1){ rowS = 0; rowE = 1; columnS = 0; columnE = 1; }
        if(column == 2 or column == 3){ rowS = 0; rowE = 1; columnS = 2; columnE = 3; }
    }
    if(row == 2 or row == 3){
        if(column == 0 or column == 1){ rowS = 2; rowE = 3; columnS = 0; columnE = 1; }
        if(column == 2 or column == 3){ rowS = 2; rowE = 3; columnS = 2; columnE = 3; }
    }
    for(ll i = rowS; i <= rowE; i++){
        for(ll j = columnS; j <= columnE; j++){ if(sudoku[i][j] == char(num+48)){ ok = false; break; } }
        if(!ok){ break; }
    }
    return ok;
}

void BT(ll x, ll y){
    if(y == 4){ x++; y = 0; }
    if(x == 4){
        for(ll i = 0; i < 4; i++) cout << sudoku[i] << endl;
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
        for(ll i = 0; i < 4; i++){ string temp; cin >> temp; sudoku.pb(temp); }
        cout << "Case #" << ++cn << ":" << endl;
        BT(0, 0);
        found = false;
        sudoku.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}