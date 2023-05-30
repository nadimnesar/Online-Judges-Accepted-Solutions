#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
#define INF                 (0x3f3f3f3f)

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

char button[10][4];
void preCal(){
    button[1][1] = '.';
    button[1][2] = ',';
    button[1][3] = '\?';
    button[1][4] = '\"';

    char pre = 'a'-1;
    for(int i = 2; i <= 6; i++){
        for(int j = 1; j <= 3; j++){
            button[i][j] = ++pre;
        }
    }

    for(int j = 1; j <= 4; j++){
        button[7][j] = ++pre;
    }

    for(int j = 1; j <= 3; j++){
        button[8][j] = ++pre;
    }

    for(int j = 1; j <= 4; j++){
        button[9][j] = ++pre;
    }

    button[0][1] = ' ';
}

void solve(){

    preCal();

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int bb[n+7];
        int cc[n+7];

        for(int i = 0; i < n; i++){
            cin >> bb[i];
        }

        for(int i = 0; i < n; i++){
            cin >> cc[i];
        }

        for(int i = 0; i < n; i++){
            cout << button[bb[i]][cc[i]];
        }
        cout << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}