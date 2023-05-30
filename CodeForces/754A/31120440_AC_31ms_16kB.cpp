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

void solve(){
    int n;
    cin >> n;
    vector < int > v;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.pb(temp);
    }
    vector < pair < int, int > > ans;

    bool bal = false;

    int i = 0;
    while(i < n){
        if(v[i] != 0) break;
        else i++;
    }
    if(i != 0) bal = true;

    while(i < n){
        if(v[i] != 0){
            int j = i+1;
            while(j < n){
                if(v[j] == 0) j++;
                else break;
            }
            if(bal){
                bal = false;
                ans.pb({1, j});
                i = j;
                continue;
            }
            ans.pb({i+1, j});
            i = j;
        }
    }
    if(ans.size()){
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }
    else cout << "NO" << endl;
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
