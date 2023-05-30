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

untype llu gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
untype void vout(vector < T > &v) { for (llu i = 0; i < v.size(); i++) {
(i + 1 == v.size()) ? (cout << v[i] << endl) : (cout << v[i] << ' '); } }
untype llu lcm(T a, T b) {a = abs(a); b = abs(b); return (a / gcd(a, b)) * b;}
untype llu binpow(T n, T p){ if(p == 0) return 1; llu res = binpow(n, p/2);
if(p%2) return res*res*n; else return res*res; }

ll nCr(ll n, ll r){
    return (((n-r)+1)*((n-r)+2))/2;
}

void solve() {
    ll t, b;
    cin >> t >> b;

    if(!t and !b) cout << '1' << endl;
    else if (t and b){
        if(t&1) cout << '0' << endl;
        else{
            double total_bacbo = -1;
            for(ll i = t; i > 0; i-= 2){
                if(total_bacbo == -1) total_bacbo = (double)(nCr(i+1, 2)-i)/nCr(i+1, 2);
                else total_bacbo *=  (double)(nCr(i+1, 2)-i)/nCr(i+1, 2);
            }
            cout << dot(6) << total_bacbo << endl;
        }
    }
    else if(!t and b)  cout << '1' << endl;
    else{
        if(t&1) cout << '0' << endl;
        else{
            double total_bacbo = -1;
            for(ll i = t; i > 0; i-= 2){
                if(total_bacbo == -1) total_bacbo = (double)(nCr(i+1, 2)-i)/nCr(i+1, 2);
                else total_bacbo *=  (double)(nCr(i+1, 2)-i)/nCr(i+1, 2);
            }
            cout << dot(6) << total_bacbo << endl;
        }
    }
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