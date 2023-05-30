#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

void solve(){
    while(true){
        double a, b, c;
        double x, y, z;
        cin >> a >> b >> c;
        cin >> x >> y >> z;

        if(a == 0 && b == 0 && c == 0 && x == 0 && y == 0 && z == 0) break;

        double p = 0, q = 0;
        if(a == x){
            if(b == y) {
                if(c != z){
                    cout << "No fixed point exists." << endl;
                    continue;
                }
                else{
                    p = a + x;
                    q = b + y;
                    double s = c + z;

                    double resx, resy;
                    resy = (((c*p)-(a*s))/((q*a)-(p*b)))*-1;
                    resx = (s - (q*resy))/p;

                    p = resx;
                    q = resy;
                }
            }
            else{
                q = (c - z) / (b - y);
                p = (c - (q*b)) / a;
            }
        }
        else{
            if(b == y){
                p = a - x / c - z;
                q = (c - (p*a)) / b;
            }
            else{
                p = a - x;
                q = b - y;
                double s = c - z;

                double resx, resy;
                resy = (((c*p)-(a*s))/((q*a)-(p*b)))*-1;
                resx = (s - (q*resy))/p;

                p = resx;
                q = resy;
            }
        }

        string rp = to_string(p);
        string rq = to_string(q);
        if(rq[rq.size()-1] == 'f' || rq[rq.size()-1] == 'f'){
            cout << "No fixed point exists." << endl;
            continue;
        }

        cout << "The fixed point is at ";

        cout << dot(2) << p << " ";
        cout << dot(2) << q << "." << endl;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}