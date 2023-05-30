#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    ll n;
    cin >> n;
    string str;
    cin >> str;
    
    stack < char > help;
    ll cnt = 0;
    
    ll first = 0, second = 0;
    
    for(ll i = 0; str[i]; i++){
        if(str[i] == '('){
            help.push(str[i]);
            first++;
        }
        else{
            if(help.empty()) cnt++;
            else help.pop();
            second++;
        }
    }
    if(cnt < 2){
        if(help.size() < 2 and first == second) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else if(help.empty()){
        if(first == second) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}
