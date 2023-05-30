#include <bits/stdc++.h>
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
 
#define MAX              (3037000499)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

map < string, ll > feq;

int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    bool br = false;
    ll t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--){
        if(br) cout << endl;
        br = true;
        ll total = 0;
        string temp;
        while(getline(cin, temp)){
            if(temp.size() == 0) break;
            feq[temp]++;
            total++;
        }
        for(auto it = feq.begin(); it != feq.end(); it++){
            cout << it->first << ' ' << dot(4) << (double)(((it->second)/(double)total)*100.00) << endl;
        }
        feq.clear();
    }
    
#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}
