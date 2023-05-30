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

map < int, int > team;


void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        team[temp] = 0;
    }

    for(int i = 0; i < 10; i++){
        int temp;
        cin >> temp;
        
        for(auto it = team.begin(); it != team.end(); it++){
            if(temp <= it->first){
                team[it->first]++;
            }
        }
    }

    int mini = 11;
    bool flag = false;
    for(auto it = team.begin(); it != team.end(); it++){
        if(it->second == 0){
            mini = min(it->first, mini);
            flag = true;
        }
    }

    if(!flag) cout << "10" << endl;
    else cout << mini << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}