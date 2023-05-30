#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (1000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

ll bits;

string dTOb(ll n){
    string res;
    for(ll i = bits-1; i >= 0; i--){
        ll k = n >> i;
        if (k&1) res += '1';
        else res += '0';
    }
    return res;
}

ll bTOd(string n){
    string num = n;
    ll dec_value = 0;
    ll base = 1;
    ll len = num.size();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

void solve(){
    ll num, move;
    cin >> num >> move;
    move = move%bits;
    string binaryF = dTOb(num);
    string res;
    for(ll j = move; j < bits; j++) res += binaryF[j];
    for(ll j = 0; j < move; j++) res += binaryF[j];
    cout << bTOd(res) << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
#endif

    ll t; cin >> bits >> t;
    // int cn = 0;
    for(int i = 0; i < t; i++){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}