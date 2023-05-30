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
#define MAX              (1e5+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))


void solve(){
    string str;
    while(getline(cin, str)){
        if(str == "0"){
            cout << 2 << ' ' << 2 << endl;
            continue;
        }
        int n = 0;
        int l = 0, r = 0;
        bool range = false;
        bool negetive = false;
        for(int i = 0; str[i]; i++){
            if(str[i] == '-') negetive = true;
            else if(str[i] == ' '){
                l = n;
                n = 0;
                range = true;
            }
            else n = (n*10) + str[i] - '0';
        }
        if(range){
            r = n;
            int res = 0;
            for(int i = l + l%2; i <= r; ){
                if(i%4){
                    res++;
                    i += 4;
                }
                else i += 2;
            }
            cout << res << endl;
            // cout << (r/4) - (l/4) + !(l%4) << endl;
            continue;
        }
        if(negetive) n *= -1;
        if(n < 0){
            n = abs(n);
            if(n&1) cout << (n/2) << ' ' << ((n/2) + (n%2)) << endl;
            else{
                if(n%4 != 0) cout << "Bachelor Number." << endl;
                else cout << (((n/2)/2) - 1) << ' ' << (((n/2)/2) + 1) << endl;
            }
        }
        else if(n&1) cout << ((n/2) + (n%2)) << ' ' << (n/2) << endl;
        else{
            if(n%4 != 0) cout << "Bachelor Number." << endl;
            else cout << (((n/2)/2) + 1) << ' ' << (((n/2)/2) - 1) << endl;
        }
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