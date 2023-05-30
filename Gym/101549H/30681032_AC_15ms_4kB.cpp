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

void solve(){
    int n;
    cin >> n;
    string young, old;
    int yY, yM, yD;
    int oY, oM, oD;
    string str;
    int Y, M, D;
    cin >> str >> D >> M >> Y;
    n -= 1;
    yM = M;
    yY = Y;
    yD = D;
    oM = M;
    oY = Y;
    oD = D;
    young = str;
    old = str;
    while(n--){
        cin >> str >> D >> M >> Y;
        if(yY < Y){
            yY = Y;
            yM = M;
            yD = D;
            young = str;
        }
        else if(yY == Y){
            if(yM < M){
                yY = Y;
                yM = M;
                yD = D;
                young = str;
            }
            else if(yM == M){
                if(yD < D){
                    yY = Y;
                    yM = M;
                    yD = D;
                    young = str;
                }
            }
        }
        if(oY > Y){
            oM = M;
            oY = Y;
            oD = D;
            old = str;
        }
        else if(oY == Y){
            if(oM > M){
                oM = M;
                oY = Y;
                oD = D;
                old = str;
            }
            else if(oM == M){
                if(oD > D){
                    oM = M;
                    oY = Y;
                    oD = D;
                    old = str;
                }
            }
        }
    }
    cout << young << endl;
    cout << old << endl;
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