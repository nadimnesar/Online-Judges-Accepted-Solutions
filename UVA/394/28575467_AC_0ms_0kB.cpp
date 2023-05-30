#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
#define pop              pop_back

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

map < string, vector < ll > > Data_C;
map < string, ll > Data_D;
map < string, ll > Data_C0;

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll N, R;
    cin >> N >> R;
    cin.ignore();
    for(ll i = 0; i < N; i++){
        string arrname; cin >> arrname;
        ll B, CD, D; cin >> B >> CD >> D;
        vector < ll > Low;
        vector < ll > Up;
        for(ll j = 0; j < D; j++){
            ll tempup, templow; cin >> templow >> tempup;
            Low.pb(templow);
            Up.pb(tempup);
        }
        vector < ll > C(D);
        C[D-1] = CD;
        for(ll j = D-2; j >= 0; j--){
            C[j] = (C[j+1]*(Up[j+1]-Low[j+1]+1));
        }
        ll C0 = B;
        for(ll j = 0; j < C.size(); j++){
            C0 -= (C[j]*Low[j]);
        }
        Data_C[arrname] = C;
        Data_D[arrname] = D;
        Data_C0[arrname] = C0;
    }
    for(ll i = 0; i < R; i++){
        cin.ignore();
        string arr;
        cin >> arr;
        ll D = Data_D[arr];
        ll ans = Data_C0[arr];
        vector < ll > ref(D);
        for(ll j = 0; j < D; j++){
            cin >> ref[j];
            ans += (Data_C[arr][j])*ref[j];
        }
        cout << arr << '[';
        for(ll j = 0; j < D; j++){
            if(j == D-1) cout << ref[j] << "] = ";
            else cout << ref[j] << ", ";
        }
        cout << ans << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}