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
    string str;
    getline(cin, str);
    string res;
    int ssize = str.size();
    int i;
    bool allok = true;
    for(i = 0; i < ssize; i++){
        if(str[i] == ' ') continue;
        else break;
    }
    for(; i < ssize; i++){
        if(str[i] == '0') continue;
        if(str[i] >= '1' and str[i] <= '9') break;
        else{
            allok = false;
            break;
        }
    }
    if(!allok){
        cout << "invalid input" << endl;
        return; 
    }
    for(; i < ssize; i++){
        if(str[i] >= '0' and str[i] <= '9'){
            res += str[i];
        }
        else{
            allok = false;
            break;
        }
    }
    if(allok){
        if(res.size() == 0) cout << 0 << endl;
        else cout << res << endl;
    }
    else{
        cout << "invalid input" << endl;
    }
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