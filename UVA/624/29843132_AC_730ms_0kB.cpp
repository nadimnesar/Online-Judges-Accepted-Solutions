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

ll n, track, maxsum, maxlen;
vector < ll > ans; vector < ll > storage;

void allcombination(vector < ll > &data, vector < ll > &storage, ll r, ll start, ll end, ll index, ll sum){
    if(storage.size() == r){
        if(sum <= n){
            if(sum >= maxsum){
                if(r >= maxlen){
                    maxlen = r;
                    maxsum = sum;
                    ans = storage;
                }
            }
        }
        return;
    }
    for(int i = start; i <= end; i++){
        storage.pb(data[index]);
        sum += data[index];
        allcombination(data, storage, r, i+1, end, index+1, sum);
        sum -= data[index];
        storage.pop();
        index++;
    }
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    
    while(cin >> n >> track){
        vector < ll > data;
        for(ll i = 0; i < track; i++){
            ll temp; cin >> temp;
            data.pb(temp);
        }
        maxsum  = 0, maxlen = 0; ans.clear();
        for(ll r = 1; r <= track; r++){
            storage.clear();
            allcombination(data, storage, r, 0, track-1, 0, 0);
        }
        for(int i = 0; i < maxlen; i++) cout << ans[i] << ' ';
        cout << "sum:" << maxsum << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
