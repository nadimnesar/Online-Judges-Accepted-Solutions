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

bool cmp(pair < char, ll > x, pair < char, ll > y){
	if(x.first == y.first) return (x.second < y.second);
	return (x.first > y.first);
}

void solve(){
	string str;
	ll k;
	cin >> str >> k;

	for(ll i = 0; i < str.size(); i++){

		if(k == 0) break;

		ll maxi = -1;
		ll idx = 0;

		vector < pair < char, ll > > temp; 

		for(ll j = i+1; j < str.size(); j++) temp.pb({str[j], j});
		sort(full(temp), cmp);

		for(ll j = 0; j < temp.size(); j++){
			if(temp[j].first <= str[i]) continue;
			else{
				if(k >= temp[j].second-i){
					for(ll p = temp[j].second; p > i; p--){
						swap(str[p], str[p-1]);
						k--;
					}
					break;
				}
			}
		}
	}

	cout << str << endl;
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