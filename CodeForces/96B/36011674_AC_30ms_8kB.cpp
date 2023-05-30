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

    ll f, s = 0;
    for(ll i = 0; str[i]; i++){
        if(str[i]  == '4') f++;
        if(str[i]  == '7') s++;
    }

    if(f == s and f+s == str.size()){
        cout << str << endl;
        return;
    }

    
    ll n = str.size();
    if(n&1) n++;

again:

    ll m = n;
    string res;
    while(m){
        res += "47";
        m -= 2;
    }

    sort(full(res));

    ll x = stoll(str);

    ll mini = LLONG_MAX;
    do{
        ll y = stoll(res);
        if(y > x){
            mini = min(mini, y);
        }
    }
    while(next_permutation(full(res)));

    if(mini == LLONG_MAX){
        n += 2;
        goto again;
    }

    cout << mini << endl;
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}