#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
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

#define maxx                (ll)(1e3+7)
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

struct customHash {
    static uint64_t nadimnesar(uint64_t x) { x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31); }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return nadimnesar(x+FIXED_RANDOM);
    }
};

void solve() {
    string str;
    cin >> str;

    string workable;

    ll zeros = 0;
    ll one = 0;
    ll six = 0;
    ll eight = 0;
    ll nine = 0;

    for(ll i = 0; i < str.size(); i++){
        if(str[i] == '0'){
            zeros++;
            continue;
        }

        if(str[i] == '1'){
            one++;
            continue;
        }

        if(str[i] == '6'){
            six++;
            continue;
        }

        if(str[i] == '8'){
            eight++;
            continue;
        }

        if(str[i] == '9'){
            nine++;
            continue;
        }

        workable += str[i];
    }

    one--;
    six--;
    eight--;
    nine--;

    while(one--) workable += '1';
    while(six--) workable += '6';
    while(eight--) workable += '8';
    while(nine--) workable += '9';

    ll rem = 0;
    ll i = 0;
    while(i < workable.size()){
        if(rem == 0 and i+1 < workable.size()){
            rem = (rem*10) + (workable[i]-'0');
            i++;
        }

        rem = (rem*10) + (workable[i]-'0');
        rem %= 7;
        i++;
    }
    
    if(rem == 0) workable += "1869";
    else if(rem == 1) workable += "6198";
    else if(rem == 2) workable += "1896";
    else if(rem == 3) workable += "1689";
    else if(rem == 4) workable += "1986";
    else if(rem == 5) workable += "1968";
    else workable += "1698";

    while(zeros--) workable += '0';

    cout << workable << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }

    solve();

    return 0;
}