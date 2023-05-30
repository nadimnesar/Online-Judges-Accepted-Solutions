#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (1e7+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

ll gcd(ll a, ll b){
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b)) * b;
}

int n; 
int res;
bool in_out;

void allcombination(vector < int > &predators, vector < int > &storage, int r, int start, int end, int index){
    if(storage.size() == r){
        ll x = 1;
        for(int i = 0; i < r; i++){
            x = lcm(x, storage[i]);
            if(x <= 0) return;
        }
        if(x > n) return;
        if(in_out) res += n/x;
        else res -= n/x;
        return;
    }
    for(int i = start; i <= end; i++){
        storage.pb(predators[index]);
        allcombination(predators, storage, r, i+1, end, index+1);
        storage.pop();
        index++;
    }
}

void solve(){
    int temp, m;
    cin >> n >> m;
    vector < int > predators;
    for(int i = 0; i < m; i++){
        cin >> temp;
        predators.pb(temp);
    }
    sort(full(predators));
    for(int i = 0; i < m; i++){
        if(predators[i] == 0) continue;
        for(int j = i+1; j < m; j++){
            if(predators[j] == 0) continue;
            if(predators[j]%predators[i] == 0) predators[j] = 0;
        }
    }
    remove(predators, 0);
    m = predators.size();
    // debug(m);
    res = n;
    in_out = false;
    for(int r = 1; r <= m; r++){
        vector < int > storage;
        allcombination(predators, storage, r, 0, m-1, 0);
        in_out = !in_out;
    }
    cout << res << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
       solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}