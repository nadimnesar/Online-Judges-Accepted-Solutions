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

#define bug              cout << "!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define EPS              (1e-7)
#define MAX              (5000001)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

llu phi[MAX];
void dp_to_phi_1_to_MAX(){
    phi[0] = 0; phi[1] = 1;
    for(llu i = 2; i < MAX; i++) phi[i] = i;
    for(llu i = 2; i < MAX; i++){
        if(phi[i] == i){
            for (ll j = i; j < MAX; j += i) phi[j] -= phi[j]/i;
        }
        phi[i] = phi[i-1]+(phi[i]*phi[i]);
    }
}

int main(){
 
    FastIO;
    dp_to_phi_1_to_MAX();
    llu cn = 0, t; cin >> t;
    while(t--){
        llu a, b; cin >> a >> b;
        cout << "Case " << ++cn << ": ";
        cout << phi[b] - phi[a-1] << endl;
    }

}