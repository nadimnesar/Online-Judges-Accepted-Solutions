#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
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

#define maxx                (ll)(1e3+7)
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

void solve(){
    string str1, str2;
    while(cin >> str1 >> str2){

        bool flag = false;

        ll max1 = 1;
        ll max2 = 1;
        for(ll i = 0; str1[i]; i++){
            if(str1[i] >= '0' && str1[i] <= '9') max1 = max(max1, (ll)str1[i]-'0');
            else max1 = max(max1, (ll)str1[i]-55);
        }
        for(ll i = 0; str2[i]; i++){
            if(str2[i] >= '0' && str2[i] <= '9') max2 = max(max2, (ll)str2[i]-'0');
            else max2 = max(max2, (ll)str2[i]-55);
        }

        for(ll i = max1+1; i <= 36; i++){
            ll x = toDec(str1, i);
            for(ll j = max2+1; j <= 36; j++){
                ll y = toDec(str2, j);

                if(x == y){
                    cout << str1 << " (base " << i << ") = " << str2 << " (base " << j << ")" << endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout << str1 << " is not equal to " << str2 << " in any base 2..36" << endl;
    }
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   /* int t, cn = 0;
    cin >> t;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        solve();
    }*/

    solve();
    
    return 0;
}