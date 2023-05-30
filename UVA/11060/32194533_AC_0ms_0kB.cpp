#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

string temp1, temp2;
int n;

unordered_map < string, int > mark;
unordered_map < int, string > name;
unordered_map < int, int > dgree;
vector < int > depended[101];

void solve(){
    int cn = 0;
    while(cin >> n){
        mark.clear();
        name.clear();
        for(int i = 0; i < n; i++){
            cin >> temp1;
            mark[temp1] = i;
            name[i] = temp1;
            depended[i].clear();
        }

        dgree.clear();
        int q; cin >> q;
        for(int i = 0; i < q; i++){
            cin >> temp1 >> temp2;
            depended[mark[temp1]].pb(mark[temp2]);
            dgree[mark[temp2]]++;
        }

        priority_queue < int, vector < int >, greater < int > > pq;
        for(int i = 0; i < n; i++){
            if(dgree[i] == 0) pq.push(i);
        }

        cout << "Case #" << ++cn << ": Dilbert should drink beverages in this order:";
        while(!pq.empty()){
            cout << ' ' << name[pq.top()];
            int x = pq.top();
            pq.pop();
            for(int i = 0; i < depended[x].size(); i++){
                dgree[depended[x][i]]--;
                if(dgree[depended[x][i]] == 0) pq.push(depended[x][i]);
            }
        }
        cout << '.' << endl << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}