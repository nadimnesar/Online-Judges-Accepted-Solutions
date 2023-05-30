#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int 
#define ll               long long int
#define pop              pop_back
#define pb               push_back
#define mp               make_pair

#define full(x)          x.begin(), x.end()
#define iremove(x, y)    x.erase(x.begin() + y)
#define dot(x)           fixed << setprecision(x)
#define Clock            clock_t tStart = clock()
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(distance(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

vector < set < pair < ll, ll > >  > allres(80);

void allpermutations(vector < ll > &data, ll start){
    if(start == 10){
        double left = 0;
        double right = 0;
        for(ll i = 0; i < 5; i++) left = (left*10) + data[i];
        for(ll i = 5; i < 10; i++) right = (right*10) + data[i];
        double res = max(left, right)/min(left, right);
        if(res == int(res)) allres[int(res)].insert(mp(max(left, right), min(left, right)));
        return;
    }
    for(ll i = start; i < 10; i++){
        swap(data[i], data[start]);
        allpermutations(data, start+1);
        swap(data[i], data[start]);
    }
}

ll digits(ll n){
    return floor(log10(n)+1);
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    vector < ll > data;
    for(ll i = 0; i <= 9; i++) data.pb(i);
    allpermutations(data, 0);

    bool br = false;
    ll n;
    while(cin >> n and n){
        if(br) cout << endl;
        br = true;
        ll arn = allres[n].size();
        if(arn == 0) cout << "There are no solutions for " << n << "." << endl;
        else{
            for(auto it = allres[n].begin(); it != allres[n].end(); it++){
                ll firstdigit = 5-digits((*it).first);
                ll seconddigit = 5-digits((*it).second);
                while(firstdigit--) cout << '0';
                cout << (*it).first << " / "; 
                while(seconddigit--) cout << '0';
                cout << (*it).second << " = " << n << endl;
            }
        }
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}