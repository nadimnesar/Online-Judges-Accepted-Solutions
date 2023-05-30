/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;

#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
 
#define all(x)           x.begin(), x.end()
#define dot(x)           fixed << setprecision(x)
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
 
#define PI               acos(-1.0) //3.1415926535897932
#define LOG(b, x)        (log(x)/log(b))
#define EPS              (1e-7)

ll BIGMOD(ll base, ll power, ll mod){
    if(power == 0) return 1;
    else if(power&1) return (BIGMOD(base, power-1, mod)*base)%mod;
    else{
        ll oneside = BIGMOD(base, power/2, mod);
        return (oneside*oneside)%mod;
    }
}


int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fastIO;

    ll Base, Power, Mod;
    while(cin >> Base >> Power >> Mod){
        cout << BIGMOD(Base, Power, Mod)%Mod << endl;
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}
