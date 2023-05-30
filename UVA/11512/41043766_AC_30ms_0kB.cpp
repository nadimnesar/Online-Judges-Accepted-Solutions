#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define untype              template<typename T>
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define base                (ll)997
#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

untype llu GCD(T a, T b) {if (b == 0) return a; return GCD(b, a % b);}
untype void vout(vector < T > &v) { for (llu i = 0; i < v.size(); i++) {
(i + 1 == v.size()) ? (cout << v[i] << endl) : (cout << v[i] << ' '); } }
untype llu LCM(T a, T b) {a = abs(a); b = abs(b); return (a / GCD(a, b)) * b;}
untype llu binpow(T n, T p){ if(p == 0) return 1; llu res = binpow(n, p/2);
if(p%2) return res*res*n; else return res*res; }

struct customHash {
    static uint64_t nadimnesar(uint64_t x) { x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31); }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return nadimnesar(x+FIXED_RANDOM);
    }
};

ll hashTable[maxx];
ll basePow[maxx];

void init(){
    basePow[0] = 1;
    for(ll i = 1; i < maxx; i++){
        basePow[i] = (basePow[i-1]*base)%mod;
    }
}

ll get_hashValue(string str){
    ll res = 0;
    for(ll i = 0; str[i]; i++){
        res *= base;
        res %= mod;
        res += (str[i] - 'a' + 1);
    }
    return res;
}

void build_hashTable(string str){
    hashTable[0] = (str[0] - 'a' + 1);
    for(ll i = 1; str[i]; i++){
        hashTable[i] = ((hashTable[i-1]*base)%mod + (str[i] - 'a' + 1))%mod;
    }
}

ll get_subHash(ll left, ll right){
    return (ll)((hashTable[right]+mod) - ((hashTable[left-1]*basePow[right-left+1])%mod))%mod;
}

typedef struct node
{
    ll s, e;
    ll count = 0;
} node;

void solve() {
    string str;
    cin >> str;

    ll n = str.size();

    for(ll i = 0; i < n; i++) str[i] = tolower(str[i]);

    build_hashTable(str);

    ll maxLen = -1;
    ll left = 1;
    ll right = n;
    while(right >= left){
        ll mid = left + (right-left)/2;

        bool flag = false;
        gp_hash_table < ll, ll, customHash> fq;
        for(ll i = 0; i < n-(mid-1); i++){
            ll hashv = get_subHash(i, i+(mid-1));
            fq[hashv]++;

            if(fq[hashv] >= 2){
                flag = true;
                break;
            }
        }

        if(flag){
            maxLen = mid;
            left = mid+1;
        }
        else right = mid-1;
    }

    if(maxLen == -1){
         cout << "No repetitions found!" << endl;
         return;
    }

    gp_hash_table < ll, node, customHash> mp;
    for(ll i = 0; i < n-(maxLen-1); i++){
        ll hashv = get_subHash(i, i+(maxLen-1));
        mp[hashv].count++;
        mp[hashv].s = i;
        mp[hashv].e = i+(maxLen-1);
    }

    vector < pair < string, ll > > allres;
    
    for(auto it: mp){
        if(it.second.count >= 2){
            allres.pb({str.substr(it.second.s, (it.second.e-it.second.s)+1), it.second.count});
        }
    }

    sort(full(allres));
    string res = allres[0].first;
    for(ll i = 0; i < maxLen; i++) cout << char(toupper(res[i]));
    cout << ' ' << allres[0].second << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    init();
    int t, cn = 0;
    cin >> t;
    while (t--) solve();

    return 0;
}