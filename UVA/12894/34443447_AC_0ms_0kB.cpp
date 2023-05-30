#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define popb                pop_back
#define in                  insert

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define dot(x)              fixed<<setprecision(x)

#define EPS                 (double)(1e-7)
#define MAX                 (ll)(1e5+7)
#define MOD                 (ll)(1e9+7)
#define PI                  (double)(acos(-1.0))
#define LOG(b, x)           (double)(log(x)/log(b))
#define INF                 (0x3f3f3f3f)

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

void solve(){


    ll t;
    cin >> t;
    while(t--){

        double x0, y0, x1, y1, cx, cy, r;
        cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;

        double width = sqrt((y1-y0)*(y1-y0));
        double length = sqrt((x1-x0)*(x1-x0));

        double cleft = sqrt((cx-x0)*(cx-x0));
        double cright = sqrt((cx-x1)*(cx-x1));

        double cup = sqrt((cy-y1)*(cy-y1));
        double cdown = sqrt((cy-y0)*(cy-y0));

        bool ok = false;

        if(abs((length/width) - (10.0/6.0)) <= EPS){

            if(abs((length/r) - (5.0/1.0)) <= EPS){

                if(abs((cleft/cright) - (9.0/11.0)) <= EPS){

                    if(abs(cup - cdown) <= EPS){

                        ok = true;

                    }

                }


            }
        }

        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}

int main(){

    solve();
    
    return 0;
}