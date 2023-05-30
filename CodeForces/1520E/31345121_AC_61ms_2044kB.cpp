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

void solve(){

    ll n; cin >> n;
    string str;
    cin >> str;

    ll i = 0;
    ll j = n-1;

    ll sleft = 0;
    ll sright = 0;

    ll res = 0;

    while(i <= j and i >= 0 and j < n){

        if(i == j){
            if(str[i] == '.') res += min(sleft, sright);
            break;
        }

        while(str[i] == '*' and i < n){
            sleft++;
            i++;
        }
        while(str[j] == '*' and j >= 0){
            sright++;
            j--;
        }

        if(i >= n or j < 0) break;


        if(i == j){
            if(str[i] == '.') res += min(sleft, sright);
            break;
        }

        if(i > j) break;

        // debug2(i, j);

        if(sleft == sright){
            res += sleft;
            res += sright;
            i++;
            j--;
        }
        else if(sleft < sright){
            // bug;
            res += sleft;
            i++;
        }
        else{
            res += sright;
            j--;
        }
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
