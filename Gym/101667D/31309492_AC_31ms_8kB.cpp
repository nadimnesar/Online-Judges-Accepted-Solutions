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

int binpow(int n, int p){
    if(p == 0) return 1;
    int res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

unordered_map < int , bool > um;

void solve(){
    int n, temp;
    cin >> n;
    bool ok = false;
    while(true){
        if(n == 1){
            ok = true;
            break;
        }
        if(!um[n]){
            um[n] = true;
            temp = 0;
            while(n){
                temp += binpow(n%10, 2);
                n /= 10;
            }
            n = temp;
        }
        else break;
    }
    if(ok) cout << "HAPPY" << endl;
    else cout << "UNHAPPY" << endl;
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