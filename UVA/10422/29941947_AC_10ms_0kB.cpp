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

ll dx[] = { +2, +2, -2, -2, +1, -1, +1, -1 };
ll dy[] = { +1, -1, +1, -1, +2, +2, -2, -2 };

bool found;
char chessboard[5][5];
char origin[5][5];

void origin_maker(){
    for(ll i = 0; i < 5; i++) origin[0][i] = '1';
    origin[1][0] = '0'; for(ll i = 1; i < 5; i++) origin[1][i] = '1';
    origin[2][0] = '0'; origin[2][1] = '0'; origin[2][2] = ' '; origin[2][3] = '1'; origin[2][4] = '1';
    origin[3][4] = '1'; for(ll i = 0; i < 4; i++) origin[3][i] = '0';
    for(ll i = 0; i < 5; i++) origin[4][i] = '0';
}

ll misplacement(){
    ll cont = 0;
    for(ll i = 0; i < 5; i++){
        for(ll j = 0; j < 5; j++){
            if(chessboard[i][j] == ' ') continue;
            if(origin[i][j] != chessboard[i][j]) cont++;
        }
    }
    return cont;
}

bool vaild(ll x, ll y){
    if(x < 0 or x > 4) return false;
    if(y < 0 or y > 4) return false;
    return true;
}

ll min_moves;
void BT(ll r, ll c, ll moves){
    ll rate = misplacement();
    if(rate == 0){
        min_moves = min(moves, min_moves);
        found = true;
        return;
    }
    if(rate+moves < 11){
        for(ll i = 0; i < 8; i++){
            ll p = r+dx[i], q = c+dy[i];
            if(vaild(p, q)){
                swap(chessboard[p][q], chessboard[r][c]);
                BT(p, q, moves+1);
                swap(chessboard[p][q], chessboard[r][c]);
            }
        }
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    origin_maker();
    ll t; cin >> t; cin.ignore();
    while(t--){
        vector < string > input; for(ll i = 0; i < 5; i++){ string temp; getline(cin, temp); input.pb(temp); }
        ll si, sj;
        for(ll i = 0; i < 5; i++){
            for(ll j = 0; j < 5; j++){
                chessboard[i][j] = input[i][j];
                if(input[i][j] == ' '){
                    si = i;
                    sj = j;
                }
            }
        }
        min_moves = LLONG_MAX;
        found = false;
        BT(si, sj, 0);
        if(found) cout << "Solvable in " << min_moves << " move(s)." << endl;
        else cout << "Unsolvable in less than 11 move(s)." << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
