#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e5+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll n;
vector < ll > graph[maxx];
bool visited[maxx];
vector < ll > aans;
priority_queue<int,vector<int>, greater < int > > pq;

void DFS(ll idx){
    
    visited[idx] = true;
    aans.pb(idx);
    
    for(ll i = 0; i < graph[idx].size(); i++){
        pq.push(graph[idx][i]);
    }
    
    while(!pq.empty()){
        if(!visited[pq.top()]){
            DFS(pq.top());
            break;
        }
        pq.pop();
    }
}

void solve(){
    ll m;
    cin >> n >> m;
    
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    DFS(1);

    for(ll i = 0; i < n; i++){
        if(i+1 == n) cout << aans[i] << endl;
        else cout << aans[i] << ' ';
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}