#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    ll n;
    cin >> n;
    vector < pair < ll, ll > > arr, copy;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        arr.pb({temp, i});
        copy.pb({temp, i});
    }

    string str;
    cin >> str;

    ll pre[n+7];
    for(ll i = 0; i < str.size(); i++){
        if(i == 0){
            if(str[i] == '0') pre[i] = 0;
            else pre[i] = 1;
        }
        else{
            if(str[i] == '0') pre[i] = pre[i-1];
            else pre[i] = pre[i-1]+1;
        }
    }

    sort(full(copy));

    bool flag = true;
    for(ll i = 0; i < arr.size(); i++){
        if(arr[i] != copy[i]){
            ll y = arr[i].second;
            ll x = copy[i].second;

            ll one;
            if(y == 0) one = pre[x-1];
            else one = pre[x-1] - pre[y-1];

            if(one < (x - y)){
                flag = false;
                break;
            }
        }
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
 
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    
    return 0;
}