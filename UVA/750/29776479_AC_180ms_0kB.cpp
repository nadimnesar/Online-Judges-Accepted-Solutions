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

set < vector < pair < ll , ll > > > solutions;

bool checker(vector < vector < ll > > &chessboard, ll r, ll c){
    for(ll i = 1; i <= 8; i++){
        if(chessboard[r][i] == 1) return false;
    }
    for(ll i = 1; i <= 8; i++){
        if(chessboard[i][c] == 1) return false;
    }
    ll x = r, y = c;
    while(true){
        if(x < 1 or x > 8) break;
        if(y < 1 or y > 8) break;
        if(chessboard[x][y] == 1) return false;
        x--; y--;
    }
    x = r; y = c;
    while(true){
        if(x < 1 or x > 8) break;
        if(y < 1 or y > 8) break;
        if(chessboard[x][y] == 1) return false;
        x++; y++;
    }
    x = r; y = c;
    while(true){
        if(x < 1 or x > 8) break;
        if(y < 1 or y > 8) break;
        if(chessboard[x][y] == 1) return false;
        x++; y--;
    }
    x = r; y = c;
    while(true){
        if(x < 1 or x > 8) break;
        if(y < 1 or y > 8) break;
        if(chessboard[x][y] == 1) return false;
        x--; y++;
    }
    return true;
}

bool okborad(vector < vector < ll > > &chessboard){
    ll cnt = 0;
    for(ll i = 1; i <= 8; i++){
        for(ll j = 1; j <= 8; j++){
            if(chessboard[i][j] == 1) cnt++;
        }
    }
    if(cnt == 8) return true;
    else return false;
}

void BT(vector < vector < ll > > &chessboard, ll x, ll y){
    if(y == 9){ y = 0; x++; }
    if(x == 9){
        if(okborad(chessboard)){
            vector < pair < ll , ll > > temp;
            for(ll i = 1; i <= 8; i++){
                for(ll j = 1; j <= 8; j++){
                    if(chessboard[i][j] == 1){
                        temp.pb(mp(j, i));
                    }
                }
            }
            sort(full(temp));
            solutions.insert(temp);
        }
        return;
    }
    if(chessboard[x][y] == 0){
        if(checker(chessboard, x, y)){
            chessboard[x][y] = 1;
            BT(chessboard, x, y+1);
            chessboard[x][y] = 0;
        }
    }
    BT(chessboard, x, y+1);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    bool br = false;
    ll t; cin >> t;
    while(t--){
        if(br) cout << endl;
        br = true;
        ll x, y, cnt = 1; cin >> x >> y;
        vector < ll > temp(9, 0); vector < vector < ll > > chessboard(9, temp);
        chessboard[x][y] = 1;
        BT(chessboard, 1, 1);
        cout << "SOLN       COLUMN" << endl;
        cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        for(auto it = solutions.begin(); it != solutions.end(); it++){
            if(cnt > 9) cout << cnt++ << "      ";
            else cout << ' ' << cnt++ << "      ";
            for(ll i = 0; i < (*it).size(); i++){
                if(i+1 == (*it).size()) cout << (*it)[i].second << endl;
                else cout << (*it)[i].second << ' ';
            }
        }
        solutions.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}