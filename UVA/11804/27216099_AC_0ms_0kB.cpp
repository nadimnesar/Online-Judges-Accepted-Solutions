/*BISMILLAHIR RAHMANIR RAHIM*/
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

bool compare(pair < string , pair < int, int > > a, pair < string , pair < int, int > > b){
    if(a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first > b.second.first;
}

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        vector < pair < string , pair < int, int > > > x;
        for(int i = 0; i < 10; i++){
            string str;
            int attackpower, defendpower;
            cin >> str >> attackpower >> defendpower;
            x.pb({str, {attackpower, defendpower}});
        }
        sort(full(x));
        sort(full(x), compare);
        sort(x.begin(), x.begin()+5);
        sort(x.begin()+5, x.end());
        cout << "Case " << ++cn <<":" << endl;
        for(int i = 0; i < 5; i++){
            if(i == 0) cout << '(';
            if(i != 4) cout << x[i].first << ", ";
            else cout << x[i].first;
            if(i == 4) cout << ')' << endl;
        }
        for(int i = 5; i < 10; i++){
            if(i == 5) cout << '(';
            if(i != 9) cout << x[i].first << ", ";
            else cout << x[i].first;
            if(i == 9) cout << ')' << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}