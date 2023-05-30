#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e7+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

vector < ll > primes;
vector < bool > ifprime(maxx);

void sieve(){
    for(ll i = 3; i*i <= maxx; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < maxx; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(1);
    primes.pb(2);
    for(ll i = 3; i < maxx; i+=2) if(!ifprime[i]) primes.pb(i);
}

vector < string > grid;

ll n;
ll u;
ll res = 0;

bool check(ll r, ll c){
    if(r < 0 or r >= n) return false;
    if(c < 0 or c >= n) return false;
    if(grid[r][c] == 'x') return false;
    return true;
}

ll dx[5] = {0, +0, 0, 1, -1};
ll dy[5] = {0, -1, 1, 0, +0};

void flood_fill(ll x, ll y){

    for(ll i = 0; i < 5; i++){
        ll p = dx[i]+x;
        ll q = dy[i]+y;

        if(check(p, q)){

            res += primes[u++];

            grid[p][q] = 'x';
            flood_fill(p, q);
        }
    }
}

void solve(){

    string temp;
    cin >> n;

    for(ll i = 0; i < n; i++){
        cin >> temp;
        grid.pb(temp);
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){

            if(grid[i][j] == '.'){
                u = 0;

                res += primes[u++];
                grid[i][j] = 'x';

                flood_fill(i, j);
            }
        }
    }
    cout << res << endl;
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    sieve();
    solve();
    
    return 0;
}
