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

vector < ll > lucky;
vector < ll > vlucky;
void BT(vector < char > &digits, string &store, int limit){
    if(store.size() == limit){
        ll num = 0;
        for(int i = 0; i < limit; i++) num = (num*10) + (store[i]-48);
        lucky.pb(num);
        return;
    }
    for(int i = 0; i < 2; i++){
        store.pb(digits[i]);
        BT(digits, store, limit);
        store.pop();
    }
}

void againBT(int pos, ll value){
    if(value > 1) vlucky.pb(value);
    for(int i = pos; i < 8190; i++){
        if((value*lucky[i]) <= 0 or (value*lucky[i]) > (ll)1e12) return;
        againBT(i, value*lucky[i]);
    }
}

void magic(){
    vector < char > digits; digits.pb('4'); digits.pb('7');
    for(int i = 1; i <= 12; i++){
        string store;
        BT(digits, store, i);
    }
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