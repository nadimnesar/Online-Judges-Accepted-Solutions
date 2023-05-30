#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define untype              template<typename T>
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(2e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

untype llu GCD(T a, T b) {if (b == 0) return a; return GCD(b, a % b);}
untype void vout(vector < T > &v) { for (llu i = 0; i < v.size(); i++) {
(i + 1 == v.size()) ? (cout << v[i] << endl) : (cout << v[i] << ' '); } }
untype llu LCM(T a, T b) {a = abs(a); b = abs(b); return (a / GCD(a, b)) * b;}
untype llu binpow(T n, T p){ if(p == 0) return 1; llu res = binpow(n, p/2);
if(p%2) return res*res*n; else return res*res; }

ll n, res;
bool inclusion;

void AllCombination(vector < ll > &data, vector < ll > &storage, ll r, ll start, ll end, ll index){
    if(storage.size() == r){
        ll lcm = storage[0];
        for(ll i = 1; i < storage.size(); i++) lcm = LCM(lcm, storage[i]);
        inclusion ? res += (n/lcm) : res -= (n/lcm);
        return;
    }

    for(int i = start; i <= end; i++){
        storage.pb(data[index]);
        AllCombination(data, storage, r, i+1, end, index+1);
        storage.ppb();
        index++;
    }
}


void solve() {
    ll m;
    cin >> n >> m;

    vector < ll > v;
    for(ll i = 0; i < m; i++){
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    res = 0;
    inclusion = true;
    for(ll r = 1; r <= m; r++){
        vector < ll > storage;
        AllCombination(v, storage, r, 0, v.size()-1, 0);
        inclusion = !inclusion;
    }

    cout << n-res << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t, cn = 0;
    cin >> t;
    while (t--) {
        cout << "Case " << ++cn << ": ";
        solve();
    }
    // solve();
    return 0;
}