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

vector < pair < ll , ll > > graph[maxx];
bool flag[maxx];
ll leaf, mx;

void DFS(ll at, ll dis, ll s){
    flag[at] = true;

    if(at != s and graph[at].size() == 1){
        if(dis > mx){
            mx = dis;
            leaf = at;
        }
    }

    for(ll i = 0; i < graph[at].size(); i++){
        if(!flag[graph[at][i].first]){
            DFS(graph[at][i].first, dis + graph[at][i].second, s);
        }
    }
}

void nadimnesar() {
    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++) graph[i].clear(), flag[i] = false;

    for(ll i = 0; i < n-1; i++){
        ll x, y, w;
        cin >> x >> y >> w;
        graph[x].pb({y, w});
        graph[y].pb({x, w});
    }

    mx = 0;
    DFS(0, 0, 0);

    mx = 0;
    memset(flag, false);

    DFS(leaf, 0, leaf);

    cout << mx << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}