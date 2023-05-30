#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))

void solve(){
    int n;
    cin >> n;
    vector < int > arr;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
    
        arr.pb(x);
        arr.pb(y);
    }

    sort(full(arr));

    vector < int > res_x;
vector <int> res_y;

    for(int i = 0; i < n; i++){
        res_x.pb(arr[i]);
    }
for(int i = n; i < 2*n; i++){
res_y.pb(arr[i]);
}
sort(full(res_y), greater <int > ());
for(int i=0; i < n; i++){
if(i+1 == n) cout << res_x[i] << ' ' << res_y[i] << endl;
else cout << res_x[i] << ' ' << res_y[i] << ' ';
}
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}