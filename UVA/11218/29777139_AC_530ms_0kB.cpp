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

ll score;

void allcombination(vector < pair < vector < ll > , ll > > &data, vector < pair < vector < ll > , ll > > &storage, ll r, ll start, ll end, ll index){
    if(storage.size() == r){
        for(ll i = 0; i < 3; i++){
            for(ll j = i+1; j < 3; j++){
                for(ll k = 0; k < 3; k++){
                    for(ll p = 0; p < 3; p++){
                        if((storage[i].first)[k] == (storage[j].first)[p]) return;
                    }
                }
            }
        }
        score = max(score, storage[0].second + storage[1].second + storage[2].second);
        return;
    }
    for(int i = start; i <= end; i++){
        storage.pb(data[index]);
        allcombination(data, storage, r, i+1, end, index+1);
        storage.pop();
        index++;
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll n, cn = 0;
    while(cin >> n and n){
        vector < pair < vector < ll > , ll > > data;
        for(ll i = 0; i < n; i++){
            vector < ll > temp;
            ll a, b, c, s; cin >> a >> b >> c >> s;
            temp.pb(a); temp.pb(b); temp.pb(c);
            data.pb(mp(temp, s));

        }
        vector < pair < vector < ll > , ll > > storage;
        allcombination(data, storage, 3, 0, n-1, 0);
        cout << "Case " << ++cn << ": ";
        if(score == 0) cout << "-1" << endl;
        else cout << score << endl;
        score = 0;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}