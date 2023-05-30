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
    ll k;
    cin >> k;

    cin.ignore();

    string s;
    getline(cin, s);

    vector < ll > v;
    string temp;

    for(ll i = 0; i < s.size(); i++){
        temp += s[i];

        if(s[i] == ' '){
            v.pb(temp.size());
            temp.clear();
        }
        if(s[i] == '-'){
            v.pb(temp.size());
            temp.clear();
        }
    }
    v.pb(temp.size());

    ll low = 0;
    ll high = s.size();
    ll res = s.size();

    while(low <= high){
        ll mid = (low+high)/2;

        ll sum = 0;
        ll mx = 0;
        ll cnt = 0;
        ll flag = 0;

        for(ll i = 0; i < v.size(); i++){
            if(sum+v[i] <= mid) sum += v[i];
            else{
                mx = max(sum, mx);
                sum = v[i];
                cnt++;
                if(i == v.size()) flag = 1;
            }
        }

        if(!flag){
            mx = max(sum, mx);
            cnt++;
        }

        if(cnt <= k){
            res = min(res, mx);
            high = mid-1;
        }
        else low = mid+1;
    }

    cout << res << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}