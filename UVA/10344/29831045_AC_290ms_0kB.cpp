#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int 
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

set < string > allcombination;
void BT(string &oparators, string store, ll start){
    if(store.size() == 4){
        sort(full(store));
        do{
            allcombination.insert(store);
        } while(next_permutation(full(store)));
        return;
    }
    for(ll i = start; i < oparators.size(); i++){
        store.pb(oparators[i]);
        BT(oparators, store, i);
        store.pop();
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    string oparators = "+-*";
    string store;
    BT(oparators, store, 0);

    ll a, b, c, d, e;
    while(cin >> a >> b >> c >> d >> e){
        if(a == 0 and b == 0 and c == 0 and d == 0 and e == 0) break;

        vector < ll > temporary; temporary.pb(a); temporary.pb(b); temporary.pb(c); temporary.pb(d); temporary.pb(e);
        sort(full(temporary)); vector < vector < ll > > allpermutation;
        do{ allpermutation.pb(temporary); } while(next_permutation(full(temporary)));
        ll aps = allpermutation.size();

        bool found = false;
        for(auto it = allcombination.begin(); it != allcombination.end(); it++){
            for(ll k = 0; k < aps; k++){
                ll res;
                if((*it)[0] == '+') res = allpermutation[k][0]+allpermutation[k][1];
                else if((*it)[0] == '-') res = allpermutation[k][0]-allpermutation[k][1];
                else res = allpermutation[k][0]*allpermutation[k][1];

                if((*it)[1] == '+') res = res+allpermutation[k][2];
                else if((*it)[1] == '-') res = res-allpermutation[k][2];
                else res = res*allpermutation[k][2];

                if((*it)[2] == '+') res = res+allpermutation[k][3];
                else if((*it)[2] == '-') res = res-allpermutation[k][3];
                else res = res*allpermutation[k][3];

                if((*it)[3] == '+') res = res+allpermutation[k][4];
                else if((*it)[3] == '-') res = res-allpermutation[k][4];
                else res = res*allpermutation[k][4];

                if(res == 23){
                    found = true;
                    break;
                }
            }
        }
        if(found) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}