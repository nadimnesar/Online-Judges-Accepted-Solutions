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
#define MAX              (2e7+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

llu BIGMOD(llu B, llu P, llu M){
    if(P==0) return 1;
    if(P%2==0){
        llu p1=(BIGMOD(B,P/2,M))%M;
        return (p1*p1)%M;
    }
    else{
        llu p1=B%M;
        llu p2=(BIGMOD(B,P-1,M))%M;
        return (p1*p2)%M;
    }
}

void solve(){
    int n, m;
    while(~scanf("%d %d", &n, &m)){
        m = n-m;
        ll total2 = 0;
        ll total5 = 0;
        ll x;
        ll res = 1;
        for(int i = n; i > m; i--){
            x = i;
            while(x%2 == 0){
                x /= 2;
                total2++;
            }
            while(x%5 == 0){
                x /= 5;
                total5++;
            }
            res = ((res%10) * (x%10))%10; 
        }
        int z = min(total2, total5);
        total2 -= z;
        total5 -= z;

        x = BIGMOD(2, total2, 10);
        res = ((res%10) * (x%10))%10; 
        x = BIGMOD(5, total5, 10);
        res = ((res%10) * (x%10))%10; 

        printf("%lld\n", res);
    }
}

int main(){

    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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