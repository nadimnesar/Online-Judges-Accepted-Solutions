#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <string.h>
#include <cstring>
#include <bitset>
#include <list>
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
 
#define MAX              (1e6+1)
#define MOD              (1e9+7)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

vector < ll > fact(10);

int main(){
 
/*    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif*/

    fact[0] = 1;
    for(ll i = 1; i < 10; i++){
        fact[i] = fact[i-1]*i;
    }
    ll num = fact.size();
    vector < bool > data(1000007, false);
    for(ll mask = 1; mask < (1 << num); mask++){
        ll sum = 0;
        for(ll i = 0; i < num; i++){
            if(mask&(1 << i)){
                sum += fact[i];
            }
        }
        data[sum] = true;
    }
    ll n;
    while(cin >> n){
        if(n < 0) break;
        if(data[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

/*#ifndef ONLINE_JUDGE
    Runtime;
#endif*/
 
}