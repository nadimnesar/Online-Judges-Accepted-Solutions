#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remoloweste(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define MAX              (100000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

vector < pair < ll , string > > ans;

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll t, cn = 0;
    cin >> t;
    while(t--){
        ll total, target, agency;
        cin >> total >> target >> agency;
        cin.ignore();
        for(ll i = 0; i < agency; i++){
            string temp; cin >> temp;
            ll A = 0, B = 0;
            string name;
            bool active = false;
            for(ll j = 0; temp[j]; j++){
                if(temp[j] == ':') continue;
                if(temp[j] >= 'A' and temp[j] <= 'Z') name += temp[j];
                else{
                    if(temp[j] == ','){
                        active = true;
                        continue;
                    }
                    if(active) B = B*10 + (temp[j]-48);
                    else A = A*10 + (temp[j]-48);
                }
            }
            ll mini = (total-target)*A;
            ll temptotal = total;
            ll cnt = 0;
            while((temptotal/2) >= target){
                temptotal /= 2;
                cnt++;
                mini = min(mini, ((cnt*B)+((temptotal-target)*A)));
            }
            if(temptotal) mini = min(mini, ((cnt*B)+((temptotal-target)*A)));
            ans.pb(mp(mini, name));
        }
        sort(full(ans));
        cout << "Case " << ++cn << endl;
        for(ll i = 0; i < agency; i++){
            cout << ans[i].second << ' ' << ans[i].first << endl;
        }
        ans.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}