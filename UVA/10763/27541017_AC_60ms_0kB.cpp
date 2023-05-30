#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
#define pop              pop_back
 
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

map < int , int > candidateA;
map < int , int > candidateB;

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll n;
    while(cin >> n and n){
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            candidateA[x]++;
            candidateB[y]++;
        }
        bool yes = true;
        for(auto it1 = candidateA.begin(), it2 = candidateB.begin(); it1 != candidateA.end() and it2 != candidateB.end(); it1++, it2++){
            if((it1 -> first) == it2 -> first){
                if((it1 -> second) != (it2 -> second)){
                    yes = false;
                    break;
                }
            }
            else{
                yes = false;
                break;
            }
        }
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
        candidateA.clear();
        candidateB.clear();
    }
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}