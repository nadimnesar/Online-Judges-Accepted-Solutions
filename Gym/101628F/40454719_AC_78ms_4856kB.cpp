#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define endl                '\n'
#define pb                  push_back
#define full(x)             x.begin(),x.end()
#define maxx                (ll)(3e4+7)
#define inf                 (ll)(1e12)
#define pi                  pair < ll, ll >

vector < pi > graph[maxx];
priority_queue < pi, vector< pi >, greater < pi > > pq;
ll dis[maxx];
bool pine[maxx];

void nadimnesar() {
    ll n, m;
    cin >> n >> m;
    ll t, k, p;
    cin >> t >> k >> p;

    for(ll i = 0; i < p; i++){
        ll temp;
        cin >> temp;
        pine[temp] = true;
    }

    for(ll i = 0; i < m; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        w *= 60;
        if(pine[a]) w += k;
        graph[a].pb({b, w});
    }

    for(ll i = 1; i <= n; i++) dis[i] = inf;

    dis[1] = 0;
    pq.push({0, 1});

    while(pq.size()){
        ll v = pq.top().second;
        pq.pop();

        for(ll i = 0; i < graph[v].size(); i++){
            ll u = graph[v][i].first;
            ll ucost = graph[v][i].second;

            if(dis[u] > dis[v]+ucost){
                dis[u] = dis[v]+ucost;
                pq.push({dis[u], u});
            }
        }
    }

    if(dis[n] > (t*60*1LL)) cout << "-1" << endl;
    else cout << dis[n] << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}