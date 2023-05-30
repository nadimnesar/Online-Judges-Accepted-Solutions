#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7; 
const double pi = acos(-1.0);

ll numofdigit(ll n){
    if(n == 0) return 0;

    ll at = 9;
    ll digit = 1;
    ll mul = 9;

    ll nod = 0;
    while(true){
        if(n > at){
            nod += mul*digit;
            mul *= 10;
            at = (at*10) + 9;
            digit++;
        }
        else{
            at /= 10;
            n -= at;
            nod += n*digit;
            break;
        }
    }

    return nod;
}

void solve() {

    ll n, x;
    cin >> n >> x;

    ll l = 0;
    ll h = 1e16;
    ll res = -1;
    while(l <= h){
        ll mid = (l+h)/2;

        ll digit = numofdigit(mid) - numofdigit(x-1);

        if(digit == n){
            res = mid;
            break;
        }
        else if(digit > n) h = mid-1;
        else l = mid+1;
    }

    if(res == -1) cout << res << endl;
    else cout << (res-x)+1 << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}