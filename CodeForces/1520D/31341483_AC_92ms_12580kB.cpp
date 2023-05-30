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
#define MAX              (1e6+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

unordered_map < ll, ll > um;

unordered_map < ll, ll > res_feq;

void solve(){
    ll n, temp;
    cin >> n;
    vector < pair < ll , ll > > arr;
    for(ll i = 1; i <= n; i++){
        cin >> temp;
        arr.pb({temp, temp-i});
    }
    um.clear();
    res_feq.clear();
    for(ll i = 0; i < n; i++){
        if(!um[arr[i].second]){
            um[arr[i].second] = arr[i].first;
        }
        else{
            if(arr[i].first > um[arr[i].second]){
                if(!res_feq[arr[i].second]) res_feq[arr[i].second] += 2;
                else res_feq[arr[i].second]++;
            }
        }
    }
    ll res = 0;
    for(auto it: res_feq){
        ll p = (it.second-1);
        res += (p*(p+1))/2;
        // cout << it.first << ' ' << it.second << endl;
    }
    cout << res << endl;

}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }
 
}
