#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

void hextodec(string n){
    ll decvalue = 0;
    ll base = 1;
    ll len = n.size();
    for(ll i = len-1; i >= 0; i--){
        if (n[i] >= '0' and n[i] <= '9') decvalue += (n[i]-48)*base;
        else if(n[i] >= 'A' && n[i]<='F') decvalue += (n[i]-55)*base;
        base *= 16;
    }
    printf("%llu\n", decvalue);
    return;
}

void dectohex(string n){
    ll dec = 0;
    for(ll i = 0; n[i]; i++) dec = (dec*10) + (n[i]-48);
    printf("0x%X\n", dec);
    return;
}

int main(){

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    string n;
    while(cin >> n){
        if(n[0] == '-') break;
        if(n.size() > 2){
            if(n[0] == '0' and n[1] == 'x'){
                iremove(n, 0);
                iremove(n, 0);
                hextodec(n);
            }
            else dectohex(n);
        }
        else dectohex(n);
    }
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}