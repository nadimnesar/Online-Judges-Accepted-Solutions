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
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(3e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){
	ll n, m;
	cin >> n >> m;

	ll bus = 0;
	ll have = 0;
	for(ll i = 0; i < n; i++){
		ll temp;
		cin >> temp;

		if(have+temp < m) have += temp;
		else if(have+temp == m){
			bus++;
			have = 0;
		}
		else{
			bus++;
			have = 0;

			ll x = 0;
			while(temp > x){
				bus++;
				x += m;
			}

			if(x == temp) continue;

			have = m - (x - temp);
			bus--;
		}
	}

	if(have) bus++;
	
	cout << bus << endl;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*int t, cn = 0;
    cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
    }*/

    solve();
    
    return 0;
}