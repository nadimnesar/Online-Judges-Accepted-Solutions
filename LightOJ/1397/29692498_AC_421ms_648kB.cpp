//new
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
 
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < string > sudo;
bool found;

bool subchecker(ll num, ll rowS, ll rowE, ll columnS, ll columnE){
    bool ok = true;
    for(ll i = rowS; i <= rowE; i++){
        for(ll j = columnS; j <= columnE; j++){ if(sudo[i][j] == char(num+48)){ ok = false; break; } }
        if(!ok){ break; }
    }
    return ok;
}

bool checker(ll &num, ll &row, ll &column){
    bool ok = true;
    for(ll j = 0; j < 9; j++){ if(sudo[row][j] == char(num+48)){ ok = false; break; } }
    for(ll j = 0; j < 9; j++){ if(sudo[j][column] == char(num+48)){ ok = false; break; } }
    if(row >= 0 and row <= 2 and ok){
        if(column >= 0 and column <= 2 and ok) ok = subchecker(num, 0, 2, 0, 2);
        if(column >= 3 and column <= 5 and ok) ok = subchecker(num, 0, 2, 3, 5);
        if(column >= 6 and column <= 8 and ok) ok = subchecker(num, 0, 2, 6, 8);
    }
    if(row >= 3 and row <= 5 and ok){
        if(column >= 0 and column <= 2 and ok) ok = subchecker(num, 3, 5, 0, 2);
        if(column >= 3 and column <= 5 and ok) ok = subchecker(num, 3, 5, 3, 5);
        if(column >= 6 and column <= 8 and ok) ok = subchecker(num, 3, 5, 6, 8);
    }
    if(row >= 6 and row <= 8 and ok){
        if(column >= 0 and column <= 2 and ok) ok = subchecker(num, 6, 8, 0, 2);
        if(column >= 3 and column <= 5 and ok) ok = subchecker(num, 6, 8, 3, 5);
        if(column >= 6 and column <= 8 and ok) ok = subchecker(num, 6, 8, 6, 8);
    }
    return ok;
}

bool indexFinder(ll &x, ll &y){
    ll mini = 10;
    for(ll i = 0; i < 9; i++){
        for(ll j = 0; j < 9; j++){
             if(sudo[i][j] == '.'){
                ll counter = 0;
                for(ll k = 1; k <= 9; k++){
                    if(checker(k, i, j)){
                        counter++;
                    }
                }
                if(!counter) return false;
                if(counter < mini){
                    mini = counter;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if(mini == 10){
        for(ll i = 0; i < 9; i++) cout << sudo[i] << endl;
        found = true;
        return false;
    }
    else return true;
}

void BackTrack(){
    if(found) return;
    ll x, y;
    if(indexFinder(x, y)){
        for(ll i = 1; i <= 9; i++){
            if(checker(i, x, y)){
                sudo[x][y] = (char)(i+48);
                BackTrack();
                sudo[x][y] = '.';
            }
        }
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t, cn = 0;
    cin >> t;
    while(t--){
        for(ll i = 0; i < 9; i++){ string temp; cin >> temp; sudo.pb(temp); }
        cout << "Case " << ++cn << ":" << endl;
        BackTrack();
        found = false;
        sudo.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}