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

vector < string > maze;
ll r, c;

bool valid(ll x, ll y){
    if((x < 0) or (x > (r-1))) return false;
    if((y < 0) or (y > (c-1))) return false;
    if(maze[x][y] == '*') return false;
    if(maze[x][y] == '#') return false;
    return true;
}

ll counter;
void BT_for_x(ll x, ll y, ll lost){
    if(maze[x][y] == 'x') counter = min(lost, counter);
    if(valid(x, y+1)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x][y+1] == 's') BT_for_x(x, y+1, lost+1);
        else BT_for_x(x, y+1, lost);
        maze[x][y] = temp;
    }
    if(valid(x, y-1)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x][y-1] == 's') BT_for_x(x, y-1, lost+1);
        else BT_for_x(x, y-1, lost);
        maze[x][y] = temp;
    }
    if(valid(x+1, y)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x+1][y] == 's') BT_for_x(x+1, y, lost+1);
        else BT_for_x(x+1, y, lost);
        maze[x][y] = temp;
    }
    if(valid(x-1, y)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x-1][y] == 's') BT_for_x(x-1, y, lost+1);
        else BT_for_x(x-1, y, lost);
        maze[x][y] = temp;
    }
}

void BT_for_exit(ll x, ll y, ll lost){
    if(maze[x][y] == '@') counter = min(lost, counter);
    if(valid(x, y+1)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x][y+1] == 's') BT_for_exit(x, y+1, lost+1);
        else BT_for_exit(x, y+1, lost);
        maze[x][y] = temp;
    }
    if(valid(x, y-1)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x][y-1] == 's') BT_for_exit(x, y-1, lost+1);
        else BT_for_exit(x, y-1, lost);
        maze[x][y] = temp;
    }
    if(valid(x+1, y)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x+1][y] == 's') BT_for_exit(x+1, y, lost+1);
        else BT_for_exit(x+1, y, lost);
        maze[x][y] = temp;
    }
    if(valid(x-1, y)){
        char temp = maze[x][y];
        maze[x][y] = '*';
        if(maze[x-1][y] == 's') BT_for_exit(x-1, y, lost+1);
        else BT_for_exit(x-1, y, lost);
        maze[x][y] = temp;
    }
}

int main(){

/*    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif*/

    ll life; cin >> r >> c >> life;
    ll dR, dC;
    vector < pair < ll, ll > > start;
    for(ll i = 0; i < r; i++){
        string temp; cin >> temp;
        for(ll j = 0; temp[j]; j++){
            if(temp[j] == 'x'){
                dR = i;
                dC = j;
            }
            if(temp[j] == '@') start.pb(mp(i, j));
        }
        maze.pb(temp);
    }
    ll Ssize = start.size();
    bool parbe = false;
    for(ll i = 0; i < Ssize; i++){
        ll x = start[i].first, y = start[i].second;
        ll minLife = 0;

        counter = (r*c)+1;
        BT_for_x(x, y, 0);
        minLife += counter;

        counter = (r*c)+1;
        BT_for_exit(dR, dC, 0);
        minLife += counter;

        if(minLife <= life){
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
