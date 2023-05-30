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
#define MAX              (1000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

vector < bool > ifprime(MAX);
void Sieve(){
    for(ll i = 3; i*i <= MAX; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < MAX; j += i+i){
                ifprime[j] = true;
            }
        }
    }
}

bool primalitytest(ll n){
    if(n <= 1) return false;
    else if(n == 2) return true;
    else if(n&1){
        if(!ifprime[n]) return true;
        else return false;
    }
    else return false;
}

void solve(){
    string str;
    while(cin >> str){
        if(str == "0") break;
        int n = str.size();
        int res = 2;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n-i; j++){
                string substr = str.substr(i, j);
                if(substr.size() > 6) continue;
                else{
                    int num = stoi(substr);
                    if(num > 100000) continue;
                    else{
                        if(primalitytest(num)){
                            if(num > res){
                                res = num;
                            }
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
#endif

    Sieve();
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