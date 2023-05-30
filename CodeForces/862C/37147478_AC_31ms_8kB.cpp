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
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(3e4+7)
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

void solve() {
    ll n, x;
    cin >> n >> x;

    if(n == 1){
        cout << "YES" << endl;
        cout << x << endl;
        return;
    }

    if(x == 0 and n == 2){
        cout << "NO" << endl;
        return;
    }

    if(n == 2){
        cout << "YES" << endl;
        cout << '0' << ' ' << x << endl;
        return;
    }

    cout << "YES" << endl;
    ll res = -1;
    for(ll i = 1; i <= n-3; i++){
        if(res == -1){
            res = i;
            cout << i << ' ';
        }
        else{
            res = (res^i);
            cout << i << ' ';
        }
    }

    bool flag = false;
    for(ll i = n-2; i <= 1e6; i++){
        for(ll j = i+1; j <= 1e6; j++){

            ll p;

            if(res == -1) p = (i^j);
            else p = (res^i^j);

            if((p^x) == 0){
                cout << i <<  ' ';
                cout << j << ' ' ;
                cout << '0' << ' ';
                flag = true;
                break;
            }

            if((p^x) > n-2 and (p^x) != i and (p^x) != j ){
                cout << i <<  ' ';
                cout << j << ' ' ;
                cout << (p^x) << ' ';
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}