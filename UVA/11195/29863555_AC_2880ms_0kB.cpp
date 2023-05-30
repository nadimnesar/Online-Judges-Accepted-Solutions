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

ll n;
char chessboard[20][20];
ll column[20], diagonal_left[50],  diagonal_right[50];

bool valid(ll r, ll c){
    if(column[c]) return false;
    if(diagonal_left[c+n-r]) return false;
    if(diagonal_right[c+r]) return false;
    if(chessboard[r][c] == '*') return false;
    if(chessboard[r][c] == 'Q') return false;
    return true;
}

ll res;
void BT(ll r){
    if(r == n){
        res++;
        return;
    }
    for(ll c = 0; c < n; c++){
        if(valid(r, c)){
            chessboard[r][c] = 'Q';
            column[c] = 1;
            diagonal_left[c+n-r] = 1;
            diagonal_right[c+r] = 1;
            BT(r+1);
            diagonal_right[c+r] = 0;
            diagonal_left[c+n-r] = 0;
            column[c] = 0;
            chessboard[r][c] = '.';
        }
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll cn = 0;
    while(cin >> n and n){
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < n; j++){
                cin >> chessboard[i][j];
            }
        }
        res = 0;
        BT(0);
        cout << "Case " << ++cn << ": ";
        cout << res << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
