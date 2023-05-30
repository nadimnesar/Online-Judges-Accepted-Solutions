#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define pob                 pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf
 
#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)       x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
#define fastIO              ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
#define EPS                 (1e-7)
#define MAX                 (1e6+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

unordered_map < string, int > replica;

int gcd(int a, int b){
  if (b == 0) return a;
  return gcd(b, a % b);
}

typedef struct node{
    int link;
    int cost1;
    int cost2;
} node;

int now, goal;
vector < node > graph[61];
bool flag[61];
bool found;

int resUP, resDown;

void dfs(int u, int haveUP, int haveDown){
    if(found) return;
    for(int i = 0; i < graph[u].size(); i++){
        if(!flag[graph[u][i].link]){
            flag[graph[u][i].link] = true;
            if(graph[u][i].link == goal){
                found = true;
                resUP = graph[u][i].cost2 * haveUP;
                resDown = graph[u][i].cost1 * haveDown;
                return;
            }
            dfs(graph[u][i].link, graph[u][i].cost2 * haveUP, graph[u][i].cost1 * haveDown);
        }
    }
}

void solve(){
    char ch, eh;
    int k = 1, n, m;
    node x;
    string temp1, temp2;
    while(cin >> ch){
        if(ch == '.') break;
        if(ch == '!'){
            cin >> n >> temp1 >> eh >> m >> temp2;
            if(!replica[temp1]) replica[temp1] = k++;
            if(!replica[temp2]) replica[temp2] = k++;

            int g = gcd(n, m);
            n /= g; m /= g;
            
            x.link = replica[temp2]; x.cost1 = n; x.cost2 = m;
            graph[replica[temp1]].pb(x);
            x.link = replica[temp1]; x.cost2 = n; x.cost1 = m;
            graph[replica[temp2]].pb(x);
        }
        else{
            cin >> temp1 >> eh >> temp2;
            now = replica[temp1];
            goal = replica[temp2];
            found = false;

            for(int i = 0; i < graph[now].size(); i++){
                if(graph[now][i].link == goal){
                    found = true;
                    cout << graph[now][i].cost1 << ' ' << temp1 << " = " << graph[now][i].cost2 << ' ' << temp2 << endl;
                    break;
                }
                memset(flag, false, sizeof(flag));

                flag[now] = true;
                flag[graph[now][i].link] = true;
                

                dfs(graph[now][i].link, graph[now][i].cost2, 1);

                if(found){
                    int g = gcd((graph[now][i].cost1)*resDown, resUP);
                    cout << ((graph[now][i].cost1)*resDown)/g << ' ' << temp1 << " = " << resUP/g << ' ' << temp2 << endl;
                    break;
                }
            }
            if(!found) cout << '?' << ' ' << temp1 << " = " << '?' << ' ' << temp2 << endl;
        }
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}