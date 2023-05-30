#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    int maxi = 0;
    string res;
    string str;
    while(cin >> str){
        if(str == "E-N-D"){
            if(maxi < 5){
                res = str;
                maxi = 5;
                break;
            }
        }
        while(str.size() > 0){
            if(str[0] >= 'A' and str[0] <= 'Z') break;
            if(str[0] >= 'a' and str[0] <= 'z') break;
            if(str[0] == '-') break;
            iremove(str, 0);
        }
        if(str.size() == 0) continue;
        while(str.size() > 0){
            if(str[str.size()-1] >= 'A' and str[str.size()-1] <= 'Z') break;
            if(str[str.size()-1] >= 'a' and str[str.size()-1] <= 'z') break;
            if(str[str.size()-1] == '-') break;
            iremove(str, str.size()-1);
        }
        if(str.size() == 0) continue;
        bool ok = true;
        for(int i = 0; str[i]; i++){
            if(str[i] >= 'A' and str[i] <= 'Z') continue;
            if(str[i] >= 'a' and str[i] <= 'z') continue;
            if(str[i] == '-') continue;
            ok = false;
            break;
        }
        if(ok){
            if(maxi < str.size()){
                res = str;
                maxi = str.size();
            }
        }
    }
    for(int i = 0; res[i]; i++){
        if(res[i] == '-') continue;
        else if(res[i] >= 'a' and res[i] <= 'z') continue;
        else res[i] = res[i]+32;
    }
    cout << res << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
#endif

    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}