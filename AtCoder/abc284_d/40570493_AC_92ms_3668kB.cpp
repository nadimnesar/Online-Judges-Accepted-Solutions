#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(4e7+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void nadimnesar() {
    llu n;
    cin >> n;

    llu res;
    llu cnt = 0;
    for(llu i = 2; i <= n; i++){

        while(n%i == 0){
            n /= i, cnt++;
            res = i;
        }

        if(cnt) break;
    }

    if(cnt == 0){
        double p = sqrt(n);
        llu q = p;
        if(abs(p-q) <= eps) cout << q << ' ' << 1 << endl;
        else cout << 1 << ' ' << n << endl;
    }
    else if(cnt == 1) cout << (llu)sqrt(n) << ' ' << (llu)res << endl;
    else cout << (llu)res << ' ' << (llu)n << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--) nadimnesar();
    

    return 0;
}