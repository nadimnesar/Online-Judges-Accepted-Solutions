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

ll n;
bool prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
ll chaker[17];
vector < ll > ring;


void BT(){
    if(ring.size() == n and prime[ring[n-1]+ring[0]]){
        for(ll i = 0; i < n; i++){
            if(i+1 == n) cout << ring[i] << endl;
            else cout << ring[i] << ' ';
        }
        return;
    }
    for(ll i = 2; i <= n; i++){
        if(prime[ring[ring.size()-1]+i] and !chaker[i]){
            ring.pb(i);
            chaker[i] = 1;
            BT();
            chaker[i] = 0;
            ring.pop();
        }
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    bool br = false;
    ll cn = 0;
    while(cin >> n){
        if(br) cout << endl;
        else br = true;
        ring.pb(1);
        chaker[1] = 1;
        cout << "Case " << ++cn << ":" << endl; 
        BT();
        ring.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
