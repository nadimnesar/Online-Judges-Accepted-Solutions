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
    ll n;
    cin >> n;
    ll res = 0;
    ll i = 1;
    while(i <= n){
        i = (i*10) + 1;
        res++;
    }
    i = 2;
    while(i <= n){
        i = (i*10) + 2;
        res++;
    }
    i = 3;
    while(i <= n){
        i = (i*10) + 3;
        res++;
    }
    i = 4;
    while(i <= n){
        i = (i*10) + 4;
        res++;
    }
    i = 5;
    while(i <= n){
        i = (i*10) + 5;
        res++;
    }
    i = 6;
    while(i <= n){
        i = (i*10) + 6;
        res++;
    }
    i = 7;
    while(i <= n){
        i = (i*10) + 7;
        res++;
    }
    i = 8;
    while(i <= n){
        i = (i*10) + 8;
        res++;
    }
    i = 9;
    while(i <= n){
        res++;
        i = (i*10) + 9;
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
