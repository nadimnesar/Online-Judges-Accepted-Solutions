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

bool check(ll n){
    ll nine = 0;
    ll cnt = 0;

    while(n){
        if(n%10 == 9) nine++;
        cnt++;
        n /= 10;
    }

    if(cnt&1 and nine == cnt) return true;
    else return false;
}

ll digit(ll n){
    ll cnt = 0;

    while(n){
        cnt++;
        n /= 10;
    }
    return cnt;
}

ll binpow(ll n, ll p){
    if(p == 0) return 1;
    ll res = binpow(n, p/2);
    if(p%2) return res*res*n;
    else return res*res;
}

void solve(){

    ll n;
    cin >> n;

    ll res = 0;

    while(!check(n)){
        ll dd = digit(n);
        if(dd&1){
            ll x = binpow(10, dd);
            x--;
            res += x - n;
            break;
        }

        ll num1 = 1, num2 = 1;
        string str = to_string(n);

        num1 = stoll(str.substr(0, dd/2));
        num2 = stoll(str.substr(dd/2, dd));

        if(num1 == num2){
            n = num1;
            res++;
        }
        
        if(num1 > num2){
            ll newnum;
            str = to_string(num1) + to_string(num1);
            newnum = stoll(str);

            res += newnum - n;
            res++;
            n = num1;
        }

        if(num1 < num2){
            ll newnum;
            str = to_string(num1+1) + to_string(num1+1);
            newnum = stoll(str);

            res += newnum - n;
            res++;
            n = num1+1;
        }

        /*cout << n << endl;
        cout << res << endl;
        cout << endl;*/
    }


    cout << res << endl;
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}