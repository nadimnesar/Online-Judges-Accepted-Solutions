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

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

char maze[50][50];
ll chacker[50][50];

ll r, c;

bool valid(ll x, ll y){
    if((x < 0) or (x > (r-1))) return false;
    if((y < 0) or (y > (c-1))) return false;
    if(chacker[x][y] == 1) return false;
    if(maze[x][y] == '#') return false;
    return true;
}

ll minLife;
void BT(ll x, ll y, ll lost){

    if(maze[x][y] == 'x'){
        minLife = min(lost, minLife);
        return;
    }

    for(ll i = 0; i < 4; i++){
        ll p = x + dx[i], q = y + dy[i];
        if(valid(p, q)){
            chacker[x][y] = 1;
            if(maze[p][q] == 's') BT(p, q, lost+1);
            else BT(p, q, lost);
            chacker[x][y] = 0;
        }
    }
}

int main(){

/*    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif*/

    ll life; cin >> r >> c >> life;
    vector < pair < ll , ll > > starts;
    for(ll i = 0; i < r; i++){
        for(ll j = 0; j < c; j++){
            cin >> maze[i][j];
            //cout << maze[i][j];
            if(maze[i][j] == '@') starts.pb(mp(i, j));
        }
        //cout << endl;
    }
    bool parbe = false;
    for(ll i = 0; i < starts.size(); i++){
        ll x = starts[i].first, y = starts[i].second;

        memset(chacker, 0, sizeof(chacker));
        minLife = (r*c)+1;

        BT(x, y, 0);

        if(minLife*2 <= life){
            parbe = true;
            break;
        }
    }
    if(parbe) cout << "SUCCESS" << endl;
    else cout << "IMPOSSIBLE" << endl;

/*#ifndef ONLINE_JUDGE
    Runtime;
#endif*/

}