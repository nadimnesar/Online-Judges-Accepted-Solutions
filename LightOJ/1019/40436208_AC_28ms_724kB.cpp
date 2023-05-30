#include <bits/stdc++.h>
using namespace std;

#define endl                '\n'
#define pb                  push_back
#define full(x)             x.begin(),x.end()
#define maxx                (int)(1e2+7)
#define inf                 (int)(1e6)
#define pi                  pair < int, int >

vector < pi > graph[maxx];
priority_queue < pi, vector< pi >, greater < pi > > pq;
int dis[maxx];
bool flag[maxx];

void nadimnesar() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) dis[i] = inf, flag[i] = false, graph[i].clear();

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].pb({b, w});
        graph[b].pb({a, w});
    }


    dis[1] = 0;
    pq.push({0, 1});

    while(pq.size()){
        int v = pq.top().second;
        flag[v] = true;
        pq.pop();
        for(int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i].first;
            int ucost = graph[v][i].second;

            if(flag[u]) continue;

            if(dis[u] > dis[v]+ucost){
                dis[u] = dis[v]+ucost;
                pq.push({dis[u], u});
            }
        }
    }

    if(dis[n] == inf) cout << "Impossible" << endl;
    else cout << dis[n] << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case " << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}