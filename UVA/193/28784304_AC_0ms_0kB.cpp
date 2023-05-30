#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

int n;
pair < vector < int >, int > graph[105];
int answer;
vector < int > ansnodes;

bool checker(int node){
    if(graph[node].second == 0){
        bool blackfound = true;
        for(int i = 0; i < graph[node].first.size(); i++){
            int opnode = graph[node].first[i];
            if(graph[opnode].second == 1){
                blackfound = false;
                break;
            }
        }
        return blackfound;
    }
    else return false;
}

void BT(int node, int res){
    if(node > n){
        if(res > answer){
            ansnodes.clear();
            for(int i = 1; i <= n; i++){
                if(graph[i].second == 1){
                    ansnodes.pb(i);
                }
            }
            answer = res;
        }
        return;
    }
    if(checker(node)){
        graph[node].second = 1;
        BT(node+1, res+1);
        graph[node].second = 0;
    }
    BT(node+1, res);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){ graph[i].first.clear(); graph[i].second = 0; } //0 means white, 1 means black
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            graph[a].first.pb(b); 
            graph[b].first.pb(a);
        }
        answer = 0;
        BT(1, 0);
        cout << answer << endl;
        for(int i = 0; i < ansnodes.size(); i++){
            if(i == ansnodes.size()-1) cout << ansnodes[i] << endl;
            else cout << ansnodes[i] << ' ';
        }
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
