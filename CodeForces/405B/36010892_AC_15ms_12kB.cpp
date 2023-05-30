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

    ll n;
    cin >> n;

    string str;
    cin >> str;

    ll cnt = 0;
    ll idx = -1;
    for(ll i = 0; str[i]; i++){
        if(str[i] == '.') cnt++;
        else idx = i;
    }
    if(cnt == str.size()){
        cout << cnt << endl;
        return;
    }
    
    if(cnt+1 == str.size()){
        cnt = 0;
        bool flag = false;
        for(ll i = 0; str[i]; i++){
            if(str[i] == '.') cnt++;
            else{
                if(str[i] == 'L'){
                    cnt = 0;
                    flag = true;
                }
                else{
                    cout << cnt << endl;
                    return;
                }
            }
        }

        if(flag){
            cout << cnt << endl;
            return;
        }

    }

    

    ll res = 0;

    cnt = 0;
    ll i;
    for(i = 0; str[i]; i++){
        if(str[i] == '.'){
            cnt++;
            continue;
        }
        if(str[i] == 'L') cnt = 0;
        break;
    }
    res += cnt;
    cnt = 0;

    ll j;
    for(j = n-1; j >= 0; j--){
        if(str[j] == '.'){
            cnt++;
            continue;
        }
        if(str[j] == 'R') cnt = 0;
        break;
    }
    res += cnt;

    for( ; i <= j; i++){
        if(str[i] == 'L'){
            cnt = 0;
            for(ll k = i+1; k <= j; ){
                if(str[k] == '.'){
                    cnt++;
                    k++;
                    continue;
                }
                if(str[k] == 'L'){
                    cnt = 0;
                    i = k-1;
                    break;
                }
                else{
                    res += cnt;
                    i = k-1;
                    break;
                }
            }
        }
        else{
            cnt = 0;
            for(ll k = i+1; k <= j; ){
                if(str[k] == '.'){
                    cnt++;
                    k++;
                    continue;
                }
                if(str[k] == 'R'){
                    cnt = 0;
                    i = k-1;
                    break;
                }
                else{
                    if(cnt&1) res++;
                    i = k-1;
                    break;
                }
            }
        }
    }

    cout << res << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}