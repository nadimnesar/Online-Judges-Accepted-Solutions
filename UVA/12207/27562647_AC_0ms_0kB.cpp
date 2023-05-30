#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
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

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll n, c, cn = 0;
    while(cin >> n >> c and n and c){
        cin.ignore();
        deque < ll > people;
        ll limit = min(n, (ll)1000);
        for(int i = 1; i <= limit; i++){
            people.pb(i);
        }
        cout << "Case " << ++cn << ":" << endl;
        for(int i = 0; i < c; i++){
            string cmd;
            getline(cin, cmd);
            if(cmd.size() == 1){
                ll temp = people.front();
                cout << temp << endl;
                people.pop_front();
                people.pb(temp);
            }
            else{
                ll temp;
                char ch;
                stringstream ss(cmd);
                ss >> ch >> temp;
                remove(people, temp);
                people.push_front(temp);
            }
        }
    }
    
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}