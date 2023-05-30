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

bool cmp(pair < ll, ll > p, pair < ll, ll > q){
    if(p.second > q.second) return true;
    else if(p.second < q.second) return false;
    else{
        if(p.first > q.first) return false;
        else if(p.first < q.first) return true;
    }
    return true;
}

vector < ll > x;

ll magic(vector < pair < ll, ll > > w){
    ll sum = 0;
    for(ll i = 0; i < x.size(); i++){
        for(ll j = 0; j < w.size(); j++){
            if(w[j].second == x[i]){

                pair < ll, ll > temp;
                temp = w[j];

                w.erase(w.begin()+j);

                reverse(full(w));
                
                w.pb(temp);

                reverse(full(w));

                
                break;
            }
            else sum += w[j].first;
        }
    }
    return sum;
}

void nadimnesar() {
    ll n, m;
    cin >> n >> m;

    
    vector < pair < ll, ll > > w;

    map < ll, ll > mp;
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        w.pb({temp, i});
    }

    for(ll i = 0; i < m; i++){
        ll temp;
        cin >> temp;
        temp--;
        mp[w[temp].first]++;
        x.pb(temp);
    }

    ll res = magic(w);

    vector < pair < ll, ll > > nnW;
    map < ll , bool > mp2;
    for(ll i = 0; i < x.size(); i++){
        if(!mp2[x[i]]){

            nnW.pb(w[x[i]]);

            mp2[x[i]] = true;
        }
    }

    for(ll i = 0; i < w.size(); i++){
        if(!mp2[i]) nnW.pb(w[i]);
    }

    res = min(res, magic(nnW));

    sort(full(w));

    res = min(res, magic(w));

    reverse(full(w));

    res = min(res, magic(w));


    vector < pair < ll , ll > > v2;
    for(auto it: mp){
        v2.pb({it.first, it.second});
    }

    sort(full(v2), cmp);

    vector < pair < ll, ll > > nW;

    for(ll i = 0; i < v2.size(); i++){
        for(ll j = 0; j < w.size(); j++){
            if(w[j].first == v2[i].first){
                nW.pb(w[j]);
            }
        }
    }

    res = min(res, magic(nW));

    reverse(full(nW));

    res = min(res, magic(nW));

    nW.clear();


    cout << res << endl;


}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);


    nadimnesar();
    

    return 0;
}