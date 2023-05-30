#include "bits/stdc++.h"
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
#define maxx                (ll)(1e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

vector < int > graph[maxx];
bool flag[maxx];
int res[maxx];
ll cnt;
ll now;

void DFS(ll idx){
    if(flag[idx]) return;
    flag[idx] = true;
    res[idx] = now;
    cnt++;

    for(ll i = 0; i < graph[idx].size(); i++){
        if(!flag[graph[idx][i]]) DFS(graph[idx][i]);
    }
}

void nadimnesar() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) graph[i].clear();
    memset(flag, false);
    memset(res, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        graph[x].pb(y);
        graph[y].pb(x);
    }

    map < ll, ll > mp;

    for(int i = 1; i <= n; i++){
        if(flag[i]) continue;

        now = i;
        cnt = 0;
        DFS(i);

        mp[now] = cnt;
    }

    for(ll i = 1; i <= n; i++){
        cout << mp[res[i]]-1 << ' ';
    }
    cout << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case #" << ++cn << ":" << endl;
        nadimnesar();
    }

    return 0;
}