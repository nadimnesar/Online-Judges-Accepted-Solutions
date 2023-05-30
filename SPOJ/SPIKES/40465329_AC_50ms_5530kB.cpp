#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll n, m;
ll limit;
bool flag;

ll dx[] = { -1, +1,  0,  0 };
ll dy[] = {  0,  0, +1, -1 };

bool valid(vector < string > grid, ll p, ll q){
    if(p < 0 or p >= n) return false;
    if(q < 0 or q >= m) return false;
    if(grid[p][q] == '#') return false;
    return true;
}

void BT(vector < string > grid, ll r, ll c, ll cnt){

    if(flag) return;

    if(grid[r][c] == 'x'){
        if(cnt+cnt <= limit) flag = true;
        return;
    }

    for(ll i = 0; i < 4; i++){
        ll p = r+dx[i];
        ll q = c+dy[i];

        if(valid(grid, p, q)){
            char x = grid[r][c];
            grid[r][c] = '#';

            if(x == 's') BT(grid, p, q, cnt+1);
            else BT(grid, p, q, cnt);

            grid[r][c] = x;
        }
    }

}

void nadimnesar() {
    cin >> n >> m >> limit;

    vector < string > grid;
    for(ll i = 0; i < n; i++){
        string s;
        cin >> s;
        grid.pb(s);
    }

    ll si, sj;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(grid[i][j] == '@'){
                si = i;
                sj = j;
            }
        }
    }

    BT(grid, si, sj, 0);

    if(flag) cout << "SUCCESS" << endl;
    else cout << "IMPOSSIBLE" << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}