#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back
 
#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
 
#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
 
#define EPS              (1e-7)
#define MAX              (1e5+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void solve(){
    int n;
    cin >> n;
    int last = binpow(n, 2);
    int potijon = (last/n)/2;
    vector < vector < int > > bro(n);
    int cnt = 0;
    int k = 0;
    for(int i = 1, j = last; i <= last/2; i++, j--){
        bro[k].pb(i);
        bro[k].pb(j);
        cnt++;
        if(cnt == potijon){
            cnt = 0;
            k++;
        }
    }
    for(int i = 0; i < n; i++){
        sort(full(bro[i]));
        for(int j = 0; j < bro[i].size(); j++){
            if(j+1 == bro[i].size()) cout << bro[i][j] << endl;
            else cout << bro[i][j] << ' ';
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }
 
}