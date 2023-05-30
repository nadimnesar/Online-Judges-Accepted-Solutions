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

    ll t;
    cin >> t;
    while(t--){
        string str1, str2, str3;
        string op1, op2;

        cin >> str1 >> op1 >> str2 >> op2 >> str3;

        ll a = -1, b = -1, c = -1;

        bool flag = true;
        for(ll i = 0; str1[i]; i++){
            if(str1[i] >= '0' and str1[i] <= '9') continue;
            else{
                flag = false;
                break;
            }
        }

        if(flag) a = stoi(str1);

        flag = true;
        for(ll i = 0; str2[i]; i++){
            if(str2[i] >= '0' and str2[i] <= '9') continue;
            else{
                flag = false;
                break;
            }
        }
        if(flag) b = stoi(str2);

        flag = true;
        for(ll i = 0; str3[i]; i++){
            if(str3[i] >= '0' and str3[i] <= '9') continue;
            else{
                flag = false;
                break;
            }
        }
        if(flag) c = stoi(str3);

        if(a == -1) cout << c-b << " + " << b << " = " << c << endl;
        else if(b == -1) cout << a << " + " << c-a << " = " << c << endl;
        else cout << a << " + " << b << " = " << a+b << endl;
    }
    
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}