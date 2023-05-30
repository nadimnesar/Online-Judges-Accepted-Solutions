#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll binarytodecimal(string binary){
    ll decimal = 0;
    for(ll i = binary.size()-1, j = 0; i >= 0; i--, j++){
        decimal = decimal + pow(2, j) * (binary[i]-'0');
    }
    return decimal;
}

void solve() {
    string str;
    cin >> str;

    bool flag = false;
    for(ll i = 0; str[i]; i++){
        if(flag){
            str[i] = '1';
            continue;
        }

        if(str[i] == '0' or str[i] == '1') continue;
        else{
            str[i] = '1';
            flag = true;
        }
    }

    // cout << str << endl;

    cout << binarytodecimal(str) << endl;

}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // int t, cn = 0;
    // cin >> t;
    // while (t--) {
    //     // cout << "Case " << ++cn << ": ";
    //     solve();
    // }

    solve();


    return 0;
}