#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(3e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll toDec(string str, ll base){
    ll dec_val = 0;
    for (int i = str.size() - 1, j = 0; i >= 0; i--, j++) {
        if (str[i] >= '0' && str[i] <= '9') dec_val += (int(str[i]) - 48) * pow(base, j);
        else dec_val += (int(str[i]) - 55) * pow(base, j);
    }
    return dec_val;
}

void solve() {
    string str;
    while(cin >> str){
        if(str == "0") break;

        ll maxi = 0;
        for(ll i = 0; str[i]; i++){
            if(str[i] >= '0' && str[i] <= '9') maxi = max(maxi, (ll)str[i]-'0');
            else maxi = max(maxi, (ll)str[i]-55);
        }

        for(ll base = maxi+1; base <= 100; base++){
            ll x = toDec(str, base);

            // cout << x << endl;

            ll y = sqrt(x);

            if(y*y == x){
                cout << base << endl;
                break;
            }
        }

    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    /*int t, cn = 0;
    cin >> t;
    while(t--){
        // cout << "Case #" << ++cn << ": ";
        solve();
    }*/

    solve();

    return 0;
}