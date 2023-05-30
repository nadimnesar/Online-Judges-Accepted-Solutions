#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){

    string str;
    cin >> str;

    if(str.size() < 7){
        cout << "NO" << endl;
        return;
    }
    bool flag = false;
    for(ll i = 0; i < str.size()-6; i++){
        if(str[i] == str[i+1] and  str[i+1] == str[i+2] and str[i+2] == str[i+3] and str[i+3] == str[i+4] and str[i+4] == str[i+5] and str[i+5] == str[i+6]){
            flag = true;
            break;
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}