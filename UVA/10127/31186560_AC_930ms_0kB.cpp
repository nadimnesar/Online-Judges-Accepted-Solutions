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
#define MAX              (5e4+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

bool check(string str, int n){
    ll remainder = 0;
    for(int i = 0; str[i]; i++)
        remainder = (remainder*10 + ((ll)str[i]-'0'))%n;
    if(remainder) return false;
    else return true;
}

void solve(){
    int n;
    while(~scanf("%d", &n)){
        string sq = "1";
        while(true){
            sq += '1';
            if(check(sq, n)) break;
        }
        cout << sq.size() << endl;
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
