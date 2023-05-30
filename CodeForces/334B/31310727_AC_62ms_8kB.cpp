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

void solve(){
    set < ll > x;
    set < ll >::iterator iti;
    set < ll > y;
    set < ll >::iterator itj;

    vector < pair < ll, ll > > alldata;
    set  < pair < ll, ll > > valolagena;
    for(ll i = 0; i < 8; i++){
        ll p, q;
        cin >> p >> q;
        x.insert(p);
        y.insert(q);
        alldata.pb({p, q});
        valolagena.insert({p, q});
    }
    if(valolagena.size() < 8){
        cout << "ugly" << endl;
        return;
    }

    bool ok = true;
    if(x.size() != 3) ok = false;
    if(y.size() != 3) ok = false;

    ll i, j;
    ll balerx, balery;
    bool paisi = false;
    for(iti = x.begin(), i = 1; iti != x.end(), i <= 3; iti++, i++){
        for(itj = y.begin(), j = 1; itj != y.end(), j <= 3; itj++, j++){
            if(i == 2 and j == 2){
                balerx = *iti;
                balery = *itj;
                paisi = true;
                break;
            }
            // debug2(i, j);
            if(paisi) break;
        }
    }

    for(ll i = 0; i < 8; i++){
        if(alldata[i].first == balerx and alldata[i].second == balery){
            ok = false;
            break;
        }
    }

    if(ok){
        cout << "respectable" << endl;
    }
    else{
        cout << "ugly" << endl;
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
