#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

map < int, int > um;
vector < pair < int, int > > happy;
void magic(){
    for(int i = 1; i <= 99999; i++){
        int x = i;
        int cnt = 0;
        bool flag = true;
        while(true){
            cnt++;
            if(x == 1) break;
            string str = to_string(x);
            int sum = 0;
            for(int j = 0; str[j]; j++){
                sum += (str[j]-'0')*(str[j]-'0');
            }
            if(sum == 4){
                flag = false;
                break;
            }
            x = sum;
        }
        if(flag) um[i] = cnt;
    }
    for(auto it: um) happy.pb({it.first, it.second});
}

void solve(){
    
    magic();
    int n, m;
    bool flag = 0;
    while(cin >> n >> m){
        if(flag) cout << endl;
        flag = 1;
        for(int i = 0; i < happy.size(); i++){
            if(happy[i].first >= n and happy[i].first <= m){
                cout << happy[i].first << ' ' << happy[i].second << endl;
            }
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    //ll t; cin >> t;
    //while(t--) solve();

    solve();

    
    return 0;
}