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

bool cmp(pair < int, int > x, pair < int, int > y){
    if(x.first < y.first) return true;
    else if(x.first > y.first) return false;
    else{
        if(x.second < y.second) return true;
        else if(x.second > y.second) return false;
        else return false;
    }
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector < pair < int, int > > v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.pb({min(a, b), max(a, b)});
    }
    sort(full(v), cmp);
    bool ok = true;
    int s, e;
    for(int i = 0; i < n; i++){
        if(i == 0){
            s = v[i].first;
            e = v[i].second;
            continue; 
        }
        s = max(s, v[i].first);
        e = min(e, v[i].second);

        if(s > e){
            ok = false;
            break;
        }
    }
    // debug
    if(!ok){
        cout << "-1" << endl;
        return;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        if(x >= v[i].first and x <= v[i].second) continue;
        else{
            if(x > v[i].first){
                res += x - v[i].second;
                x = v[i].second;
            }
            else{
                res += v[i].first - x;
                x = v[i].first;
            }
        }
    }
    cout << res << endl;
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
