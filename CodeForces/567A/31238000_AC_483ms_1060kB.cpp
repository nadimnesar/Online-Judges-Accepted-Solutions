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
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))    

#define EPS              (1e-7)
#define MAX              (1e5+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

int dis(int a, int b){
    if(a == 0) return abs(b);
    if(b == 0) return abs(a);
    if(a > 0 and b > 0) return abs(a-b);
    if(a < 0 and b < 0) return abs(abs(a)-abs(b));
    if(a < 0) return abs(a)+abs(b);
    if(b < 0) return abs(a)+abs(b);
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector < int > v;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.pb(temp);
    }
    sort(full(v));
    for(int i = 0; i < n; i++){
        if(i == 0){
            cout << dis(v[i], v[i+1]) << ' ' << dis(v[i], v[n-1]) << endl;
        }
        else if(i == n-1){
            cout << dis(v[i], v[i-1]) << ' ' << dis(v[i], v[0]) << endl;
        }
        else{
            cout << min(dis(v[i], v[i+1]), dis(v[i], v[i-1])) << ' ' << max(dis(v[i], v[n-1]), dis(v[i], v[0])) << endl;
        }
    }
}

int main(){
    
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

}
