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

ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void solve(){
    string str;
    bool kaprekar[40001];
    memset(kaprekar, false, sizeof(kaprekar));
    for(int i = 2; i < 40001; i++){
        str = to_string(binpow(i, 2));

        int siz = str.size(); 
        if(siz < 2) continue;

        for(int j = 0; j < siz-1; j++){
            string p = str.substr(0, j+1);
            string q = str.substr(j+1, siz);

            int x = stoi(p);
            int y = stoi(q);

            if(x and y and x+y == i){
                kaprekar[i] = true;
                break;
            }
        }
    }

    
    int t, cn = 0;
    cin >> t;
    bool sp = false;
    while(t--){
        int n, m;
        cin >> n >> m;

        if(sp) cout << endl;
        sp = true;

        cout << "case #" << ++cn << endl;
        bool flag = false;
        for(int i = n; i <= m; i++){
            if(kaprekar[i]){
                cout << i << endl;
                flag = true;
            }
        }
        if(!flag) cout << "no kaprekar numbers" << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}