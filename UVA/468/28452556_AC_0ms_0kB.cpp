#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define mp               make_pair
#define pop              pop_back

#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MAX              (10000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

map < char, ll > frq1;
map < char, ll > frq2;
map < char , char > mapping;
map < ll, char > copyfrq1;
map < ll, char > copyfrq2;

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    cin.ignore();
    bool br = false;
    while(t--){
        cin.ignore();
        if(br) cout << endl;
        br = true;
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        ll size1 = str1.size();
        ll size2 = str2.size();
        ll maxsize = max(size1, size2);
        for(ll i = 0; i < maxsize; i++){
            if(i < size1) frq1[str1[i]]++;
            if(i < size2) frq2[str2[i]]++;
        }
        for(auto it1 = frq1.begin(), it2 = frq2.begin(); it1 != frq1.end(); it1++, it2++){
            copyfrq1[it1->second] = it1->first;
            copyfrq2[it2->second] = it2->first;
        }
        for(auto it1 = copyfrq2.begin(), it2 = copyfrq1.begin(); it1 != copyfrq2.end(); it1++, it2++){
            mapping[it1->second] = it2->second;
        }
        for(ll i = 0; str2[i]; i++) cout << mapping[str2[i]];
        cout << endl;
        frq1.clear();
        frq2.clear();
        mapping.clear();
        copyfrq1.clear();
        copyfrq2.clear();
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}