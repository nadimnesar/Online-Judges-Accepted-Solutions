#include "bits/stdc++.h"
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    string s;
    cin >> s;

    ll q;
    cin >> q;
    while(q--){
        char c;
        ll l, r;
        cin >> c >> l >> r;

        if(c == 'g'){
            ll feq[26];
            memset(feq, 0);

            for(ll i = l; i <= r; i++){
                feq[s[i]-'A']++;
            }

            for(ll i = 0; i < 26; i++){
                cout << feq[i] << ' ';
            }
            cout << endl;
        }
        else sort(s.begin()+l,s.begin()+r+1);
    }    
}

int main() {

    int t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Case #" << ++cn << ":" << endl;
        nadimnesar();
    }

    return 0;
}