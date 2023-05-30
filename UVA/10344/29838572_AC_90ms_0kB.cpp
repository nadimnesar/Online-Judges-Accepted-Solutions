#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int 
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

bool found;

bool BT(vector < ll > &data, ll index, ll sum){
    if(index == 5){
        if(sum == 23) return true;
        else return false;
    }
    if(BT(data, index+1, sum*data[index])) return true;
    if(BT(data, index+1, sum+data[index])) return true;
    if(BT(data, index+1, sum-data[index])) return true;
    return false;
}

void allpermutations(vector < ll > &data, ll start){
    if(found) return;
    if(start == 4){
        if(BT(data, 1, data[0])) found = true;
        return;
    }
    for(ll i = start; i < 5; i++){
        swap(data[i], data[start]);
        allpermutations(data, start+1);
        swap(data[i], data[start]);
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e){
        if(a == 0 and b == 0 and c == 0 and d == 0 and e == 0) break;

        vector < ll > data; data.pb(a); data.pb(b); data.pb(c); data.pb(d); data.pb(e);
        allpermutations(data, 0);

        if(found) cout << "Possible" << endl;
        else cout << "Impossible" << endl;

        found = false;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
