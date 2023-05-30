#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll HtoD(string str){
    ll res = 0;
    ll p = 0;
    for(int i = str.size()-1; i >= 0; i--){
        if(str[i] >= '0' and str[i] <= '9') res += (str[i]-'0')*pow(16, p);
        else res += ((str[i]-'A')+10)*pow(16, p);
        p++;
    }
    return res;
}

string DtoB(ll n){
    string res;
    while(n){
        res += char((n%2)+'0');
        n /= 2;
    }
    while(res.size() < 13) res += '0';
    reverse(full(res));
    return res;
}

void solve(){
    ll t;
    cin >> t;
    while(t--){
        string str1, str2, op;
        cin >> str1 >> op >> str2;
        ll num1, num2;
        num1 = HtoD(str1);
        num2 = HtoD(str2);

        ll res;
        if(op == "+") res = num1 + num2;
        else res = num1 - num2;

        if(op == "+") cout << DtoB(num1) << " + " << DtoB(num2) << " = " << res << endl;
        else cout << DtoB(num1) << " - " << DtoB(num2) << " = " << res << endl;
    }
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