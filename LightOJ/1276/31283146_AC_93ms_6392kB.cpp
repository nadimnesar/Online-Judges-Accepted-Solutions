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

vector < ll > lucky, vlucky;
void BT(ll value){
    if(value > (ll)1e12) return;;
    if(value > 1) lucky.pb(value);
    BT((value*10) + 4);
    BT((value*10) + 7);
}

void againBT(int pos, ll value){
    if(value > 1) vlucky.pb(value);
    for(int i = pos; i < lucky.size(); i++){
        if((ll)(value*lucky[i]) <= 0 or (ll)(value*lucky[i]) > (ll)1e12) return;
        againBT(i, (ll)(value*lucky[i]));
    }
}

void magic(){
    BT(0);
    sort(full(lucky));
    againBT(0, 1);
    sort(full(vlucky));
    alluniq(vlucky, vlucky.size());
}

void solve(){
    ll a, b;
    cin >> a >> b;

    int indexa = (lower_bound(full(vlucky), a) - vlucky.begin())+1;
    int indexb = (lower_bound(full(vlucky), b) - vlucky.begin())+1;

    cout << ((vlucky[indexb-1] == b) ? indexb: --indexb) - (--indexa)  <<  endl;
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    magic();
    int t; cin >> t;
    int cn = 0;
    while(t--){
        cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }

}