#include <bits/stdc++.h>
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
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
    string str;
    cin >> str;

    vector < char > lis;
    for(ll i = 0; str[i]; i++){
        auto it = lower_bound(full(lis), str[i]);
        if(lis.end() == it) lis.pb(str[i]);
        else lis[it-lis.begin()] = str[i]; 
    }

    cout << 26-lis.size() << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
    
    return 0;
}