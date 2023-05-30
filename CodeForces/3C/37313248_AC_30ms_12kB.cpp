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
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

vector < string > grid;

void solve() {
    string str;
    for(ll i = 0; i < 3; i++){
        cin >> str;
        grid.pb(str);
    }

    ll x = 0;
    ll o = 0;

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 3; j++){
            if(grid[i][j] == 'X') x++;
            if(grid[i][j] == '0') o++;
        }
    }

    if(x < o){
        cout << "illegal" << endl;
        return;
    }

    if(x-o > 1){
        cout << "illegal" << endl;
        return;
    }

    ll xf = false;
    ll of = false;

    if(grid[0][0] == 'X' and grid[1][1] == 'X' and grid[2][2] == 'X') xf = true;
    if(grid[0][2] == 'X' and grid[1][1] == 'X' and grid[2][0] == 'X') xf = true;
    if(grid[0][0] == 'X' and grid[0][1] == 'X' and grid[0][2] == 'X') xf = true;
    if(grid[1][0] == 'X' and grid[1][1] == 'X' and grid[1][2] == 'X') xf = true;
    if(grid[2][0] == 'X' and grid[2][1] == 'X' and grid[2][2] == 'X') xf = true;
    if(grid[0][0] == 'X' and grid[1][0] == 'X' and grid[2][0] == 'X') xf = true;
    if(grid[0][1] == 'X' and grid[1][1] == 'X' and grid[2][1] == 'X') xf = true;
    if(grid[0][2] == 'X' and grid[1][2] == 'X' and grid[2][2] == 'X') xf = true;

    if(grid[0][0] == '0' and grid[1][1] == '0' and grid[2][2] == '0') of = true;
    if(grid[0][2] == '0' and grid[1][1] == '0' and grid[2][0] == '0') of = true;
    if(grid[0][0] == '0' and grid[0][1] == '0' and grid[0][2] == '0') of = true;
    if(grid[1][0] == '0' and grid[1][1] == '0' and grid[1][2] == '0') of = true;
    if(grid[2][0] == '0' and grid[2][1] == '0' and grid[2][2] == '0') of = true;
    if(grid[0][0] == '0' and grid[1][0] == '0' and grid[2][0] == '0') of = true;
    if(grid[0][1] == '0' and grid[1][1] == '0' and grid[2][1] == '0') of = true;
    if(grid[0][2] == '0' and grid[1][2] == '0' and grid[2][2] == '0') of = true;

    if(xf == true and of == true){
        cout << "illegal" << endl;
        return;
    }

    if(xf){
        if(x > o){
            cout << "the first player won" << endl;
            return;
        }
        else{
            cout << "illegal" << endl;
            return;
        }
    }

    if(of){
        if(x == o){
            cout << "the second player won" << endl;
            return;
        }
        else{
            cout << "illegal" << endl;
            return;
        }
    }

    if(x+o == 9){
        cout << "draw" << endl;
        return;
    }

    if(x == o){
        cout << "first" << endl;
        return;
    }

    cout << "second" << endl;
}
 
int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }

    solve();


    return 0;
}