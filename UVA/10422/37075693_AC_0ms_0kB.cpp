#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define untype              template<typename T>
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

untype llu GCD(T a, T b) {if (b == 0) return a; return GCD(b, a % b);}
untype void vout(vector < T > &v) { for (llu i = 0; i < v.size(); i++) {
(i + 1 == v.size()) ? (cout << v[i] << endl) : (cout << v[i] << ' '); } }
untype llu LCM(T a, T b) {a = abs(a); b = abs(b); return (a / GCD(a, b)) * b;}
untype llu binpow(T n, T p){ if(p == 0) return 1; llu res = binpow(n, p/2);
if(p%2) return res*res*n; else return res*res; }

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1};

ll res;
vector < string > chessboard;
vector < string > target;

ll inversion_count(){
    ll cnt = 0;
    for(ll i = 0; i < 5; i++){
        for(ll j = 0; j < 5; j++){
            if(chessboard[i][j] == ' ') continue;
            if(chessboard[i][j] != target[i][j]) cnt++;
        }
    }
    return cnt;
}

bool valid(ll r, ll c){
    if(r >= 5 or r < 0) return false;
    if(c >= 5 or c < 0) return false;
    return true;
}

void BT(ll r, ll c, ll move, ll preR, ll preC){
    ll inv = inversion_count();

    if(!inv){
        res = min(move, res);
        return;
    }

    if(move+inv < 11){
        for(ll i = 0; i < 8; i++){
            ll p = dx[i]+r;
            ll q = dy[i]+c;

            if(p == preR and q == preC) continue;

            if(valid(p, q)){
                swap(chessboard[p][q], chessboard[r][c]);
                BT(p, q, move+1, r, c);
                swap(chessboard[p][q], chessboard[r][c]);
            }
        }
    }
}


void solve() {
    for(ll i = 0; i < 5; i++){
        string str; getline(cin, str);
        chessboard.pb(str);
    }

    ll r, c;
    for(ll i = 0; i < 5; i++){
        for(ll j = 0; j < 5; j++){
            if(chessboard[i][j] == ' '){
                r = i;
                c = j;
            }
        }
    }

    res = LLONG_MAX;
    BT(r, c, 0, r, c);
    if(res >= 11) cout << "Unsolvable in less than 11 move(s)." << endl;
    else cout << "Solvable in " << res << " move(s)." << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while (t--) {
        target.pb("11111");
        target.pb("01111");
        target.pb("00 11");
        target.pb("00001");
        target.pb("00000");
        chessboard.clear();
        solve();
    }

    return 0;
}