#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e5 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

void solve() {
    string s;
    cin >> s;

    if(s.size() > 0){
        for(ll i = 0; i < s.size(); i++){
            if(s[i] == '8'){
                cout << "YES" << endl;
                cout << s[i] << endl;
                return;   
            }
            if(s[i] == '0'){
                cout << "YES" << endl;
                cout << s[i] << endl;
                return;   
            }
        }
    }

    if(s.size() > 1){
        for(ll i = 0; i < s.size(); i++){
            for(ll j = i+1; j < s.size(); j++){
                string temp;
                temp += s[i];
                temp += s[j];

                ll n = stoi(temp);
                if(n%8 == 0){
                    cout << "YES" << endl;
                    cout << n << endl;
                    return;   
                }
            }
        }
    }

    if(s.size() > 2){
        for(ll i = 0; i < s.size(); i++){
            for(ll j = i+1; j < s.size(); j++){
                for(ll k = j+1; k < s.size(); k++){
                    string s2;
                    s2 += s[i];
                    s2 += s[j];
                    s2 += s[k];
                    ll num = stoi(s2);
                    if(num%8 == 0){
                        cout << "YES" << endl;
                        cout << num << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}