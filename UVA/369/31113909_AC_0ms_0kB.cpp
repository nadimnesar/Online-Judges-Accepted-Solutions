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
#define MAX              (1e4+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    ll n, r;
    while(cin >> n >> r and n and r){
        int Ustart, Uend, Dend; 
        if(r > (n-r)){
            Ustart = r+1;
            Uend = n;
            Dend = n-r;
        }
        else{
            Ustart = (n-r)+1;
            Uend = n;
            Dend = r;
        }

        ll res = 1;
        ll single = 2;
        for(int i = Ustart; i <= Uend; i++){
            res *= i;
            if(single == Dend+1) continue;
            if(res%single == 0){
                res /= single;
                single++;
            }
        }
        cout << n << " things taken " << r << " at a time is " << res << " exactly." << endl;
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
