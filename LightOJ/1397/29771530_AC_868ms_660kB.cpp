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
    for(ll j = 0; j < 9; j++){ if(sudoku[row][j] == char(num+48)){ ok = false; break; } }
    for(ll j = 0; j < 9; j++){ if(sudoku[j][column] == char(num+48)){ ok = false; break; } }
    ll rowS, rowE, columnS, columnE;
    if(row >= 0 and row <= 2){
        if(column >= 0 and column <= 2){ rowS = 0; rowE = 2; columnS = 0; columnE = 2; }
        if(column >= 3 and column <= 5){ rowS = 0; rowE = 2; columnS = 3; columnE = 5; }
        if(column >= 6 and column <= 8){ rowS = 0; rowE = 2; columnS = 6; columnE = 8; }
    }
    if(row >= 3 and row <= 5){
        if(column >= 0 and column <= 2){ rowS = 3; rowE = 5; columnS = 0; columnE = 2; }
        if(column >= 3 and column <= 5){ rowS = 3; rowE = 5; columnS = 3; columnE = 5; }
        if(column >= 6 and column <= 8){ rowS = 3; rowE = 5; columnS = 6; columnE = 8; }
    }
    if(row >= 6 and row <= 8){
        if(column >= 0 and column <= 2){ rowS = 6; rowE = 8; columnS = 0; columnE = 2; }
        if(column >= 3 and column <= 5){ rowS = 6; rowE = 8; columnS = 3; columnE = 5; }
        if(column >= 6 and column <= 8){ rowS = 6; rowE = 8; columnS = 6; columnE = 8; }
    }
    for(ll i = rowS; i <= rowE; i++){
        for(ll j = columnS; j <= columnE; j++){ if(sudoku[i][j] == char(num+48)){ ok = false; break; } }
        if(!ok){ break; }
    }
    return ok;
}

bool indexFinder(ll &x, ll &y){
    ll mini = 10;
    for(ll i = 0; i < 9; i++){
        for(ll j = 0; j < 9; j++){
             if(sudoku[i][j] == '.'){
                ll count = 0;
                for(ll k = 1; k <= 9; k++){
                    if(checker(k, i, j)){
                        count++;
                    }
                }
                if(!count) return false;
                if(count < mini){
                    mini = count;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if(mini == 10){
        for(ll i = 0; i < 9; i++) cout << sudoku[i] << endl;
        found = true;
        return false;
    }
    else return true;
}

void BT(){
    if(found) return;
    ll x, y;
    if(indexFinder(x, y)){
        for(ll i = 1; i <= 9; i++){
            if(checker(i, x, y)){
                sudoku[x][y] = (char)(i+48);
                BT();
                sudoku[x][y] = '.';
            }
        }
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll t, cn = 0;
    cin >> t;
    while(t--){
        for(ll i = 0; i < 9; i++){ string temp; cin >> temp; sudoku.pb(temp); }
        cout << "Case " << ++cn << ":" << endl;
        BT();
        found = false;
        sudoku.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}