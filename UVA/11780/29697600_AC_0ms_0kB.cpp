#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
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
 
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll n;
    while(cin >> n and n){
        double m = n;
        double total = 0;
again:
        if(n <= 9){
            if(n == 1) total += 2;
            else if(n == 2) total += 3;
            else if(n == 3) total += 5;
            else if(n == 4) total += 6;
            else if(n == 5) total += 8;
            else if(n == 6) total += 10;
            else if(n == 7) total += 11;
            else if(n == 8) total += 13;
            else total += 8+6;
            cout << dot(2) <<  abs(total-(m*1.6)) << endl;
        }
        else{
            total += (n/5)*8;
            n = n%5;
            if(n == 0) cout << dot(2) <<  abs(total-(m*1.6)) << endl;
            else goto again;
        }
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}
