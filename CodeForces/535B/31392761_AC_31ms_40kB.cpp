#include <bits/stdc++.h>
using namespace std;
 
#define llu                 long long unsigned int
#define ll                  long long int
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define pob                 pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf
 
#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)       x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
#define fastIO              ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define EPS                 (1e-7)
#define MAX                 (4e4+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))
 
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

vector < ll > lucky;
void BT(ll value){
    if(value > (ll)1e9) return;;
    if(value > 1) lucky.pb(value);
    BT((value*10) + 4);
    BT((value*10) + 7);
}

int binarysearch(int q){
    int right = lucky.size()-1;
    int left = 0;
    int index = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if (lucky[mid] == q){
            index = mid;
            right = mid -1;
        }
        else if(lucky[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

void solve(){
    ll n;
    cin >> n;
    cout << binarysearch(n)+1 << endl;
}

int main(){
    fastIO;
    BT(0);
    sort(full(lucky));
    solve();
    return 0;
}