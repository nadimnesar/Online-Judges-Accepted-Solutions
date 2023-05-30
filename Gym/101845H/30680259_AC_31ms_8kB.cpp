#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

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
#define MAX              (100007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

bool check(ll y){
    if (y%400 == 0) return true;
    if (y%100 == 0) return false;
    if (y%4 == 0) return true;
    return false;
}

void solve(){
    ll n;
    cin >> n;
    int day = 2;
    int year = 1867;
    while(n--){
        year++;
        if(check(year)){
            day += 2;
        }
        else day++;
        if(day > 7) day -= 7;
    }
    if(day == 1) cout << "Saturday" << endl;
    else if(day == 2) cout << "Sunday" << endl;
    else if(day == 3) cout << "Monday" << endl;
    else if(day == 4) cout << "Tuesday" << endl;
    else if(day == 5) cout << "Wednesday" << endl;
    else if(day == 6) cout << "Thursday" << endl;
    else cout << "Friday" << endl;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("Input.txt", "r", stdin); freopen("Output.txt", "w", stdout);
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