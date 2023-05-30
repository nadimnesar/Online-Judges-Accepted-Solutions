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
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

vector < string > grid;
vector < ll > graph[301];
vector < ll > v;

bool flag[301];

void DFS(ll idx, ll now){
    if(flag[now]) return;

    if(now > idx and v[now] < v[idx]) swap(v[now], v[idx]);
    flag[now] = true;

    for(ll i = 0; i < graph[now].size(); i++) DFS(idx, graph[now][i]);
}


void nadimnesar() {
    ll n;
    cin >> n;
    
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    for (ll i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        grid.pb(temp);
    }


    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                graph[i].pb(j);
                graph[j].pb(i);
            }
        }
    }

    for(ll i = 0; i < n; i++){
        memset(flag, false);
        DFS(i, i);
    }

    for(ll i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);


    nadimnesar();


    return 0;
}