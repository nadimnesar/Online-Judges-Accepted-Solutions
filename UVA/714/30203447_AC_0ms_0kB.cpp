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

#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS              (1e-7)
#define MAX              (100000007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

ll pages[501];
ll n, k;
ll kfinder(ll range){
    ll res = 0, sum = 0;
    for(ll i = 0; i < n; i++){
        if(sum + pages[i] > range){
            if(sum == 0) break;
            res++; sum = 0;
        }
        sum += pages[i];
    }
    if(sum != 0) res++;
    return res;
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll t; cin >> t;
    while(t--){
        cin >> n >> k;
        ll low = LLONG_MAX, high = 0, maxi = 0;
        for(ll i = 0; i < n; i++){
            cin >> pages[i];
            high += pages[i];
            low = min(pages[i], low);
            maxi = max(pages[i], maxi);
        }
        bool have = false;
        ll mid, now_k, range;
        while(low <= high){
            mid = (low+high)/2; now_k = kfinder(mid);
            if(now_k == k){ range = mid; have = true; high = mid-1; }
            else if(now_k < k) high = mid-1;
            else low = mid+1;
        }
        if(!have) range = mid;
        if(range < maxi) range = maxi;
        vector < ll > answer[k+1];
        ll j = k;
        ll sum = 0;
        for(ll i = n-1; i >= 0; i--){
            if(sum + pages[i] > range){ sum = 0; j--; }
            if(j == i+1){
                for(ll p = i; p >= 0; p--){ answer[j].pb(pages[p]); j--; }
                break;
            }
            sum += pages[i];
            answer[j].pb(pages[i]);
        }
        for(ll i = 1; i <= k; i++){
            for(ll j = answer[i].size()-1; j >=0; j--){
                if(i != k) cout << answer[i][j] << ' ';
                else{
                    if(j != 0) cout << answer[i][j] << ' ';
                    else cout << answer[i][j] << endl;
                }
            }
            if(i != k) cout << "/ ";
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}
