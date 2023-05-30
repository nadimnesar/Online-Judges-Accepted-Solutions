#include <bits/stdc++.h>
using namespace std;
 
#define ll                  long long int
#define llu                 long long unsigned int
 
#define in                  insert
#define ppb                 pop_back
#define pb                  push_back
 
#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)
 
#define maxx                (ll)(1e5+7)
#define mod                 (ll)(998244353)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))
 
void solve(){
    ll t;
    cin >> t;
    ll cn = 0;
    while(t--){
        string judge, user;
        cin.ignore();
        getline(cin, user);
        cin >> judge;

        cout << "Case " << ++cn << ": ";

        if(user == judge) cout << "Yes" << endl;
        else{
            string cuser;
            for(ll i = 0; user[i]; i++){
                if(user[i] != ' ') cuser += user[i];
            }
            
            if(cuser != judge) cout << "Wrong Answer" << endl;
            else cout << "Output Format Error" << endl;
        }
        
    }
}
 
int main(){
 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
    solve();
    
    return 0;
}