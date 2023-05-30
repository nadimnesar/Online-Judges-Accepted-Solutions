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


bool column[15];
bool haram[15][15];
bool haram2[15][15];

ll n;
vector < string > grid;
ll res;

void BT(ll r){
    if(r == n){
        res++;
        // for(ll i = 0; i < n; i++) cout << grid[i] << endl;
        // cout << endl;
        return;
    }

    for(ll c = 0; c < n; c++){

        // cout << r << ' ' << c << endl;

        ll i, p, j, q;
        if(r == n-1 or c == n-1){
            i = r;
            j = c;
        }
        else if((n-1)-r == (n-1)-c){
            i = n-1;
            j = n-1;
        }
        else if((n-1)-r < (n-1)-c){
            i = n-1;
            j =  c + ((n-1)-r);
        }
        else{
            i = r + ((n-1)-c);
            j = n-1;
        }

        if(r == n-1 or c == 0){
            p = r;
            q = c;
        }
        else if((n-1)-r == c){
            p = n-1;
            q = 0;
        }
        else if((n-1)-r < c){
            p = n-1;
            q =  c - ((n-1)-r);
        }
        else{
            p = r + c;
            q = 0;
        }

        if(grid[r][c] != '*' and grid[r][c] != '#' and !column[c] and !haram[i][j] and !haram2[p][q]){

            grid[r][c] = '#';
            column[c] = true;
            haram[i][j] = true;
            haram2[p][q] = true;

            BT(r+1);

            grid[r][c] = '.';
            column[c] = false;
            haram[i][j] = false;
            haram2[p][q] = false;
        }
    }
}

void solve() {
    for(ll i = 0; i < n; i++){
        string str;
        cin >> str;
        grid.pb(str);
    }
    res = 0;

    memset(column, false);
    memset(haram, false);
    BT(0);

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll cn = 0;
    while(cin >> n and n){
        cout << "Case " << ++cn << ": ";
        solve();
        grid.clear();
    }

    return 0;
}