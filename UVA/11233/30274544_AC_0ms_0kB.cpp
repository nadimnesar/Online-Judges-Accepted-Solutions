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

#define bug              cout << "!!!!" << endl
#define debug(x)         cout << #x << " = " << x << endl
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define alluniq(x, y)    x.resize(dis(x.begin(), unique(x.begin(), x.begin()+ y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define debug3(x, y, z)  cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

map < string, pair < bool, string > > dic;

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock(); freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    ll n, k; cin >> n >> k;
    string temp1, temp2;
    while(n--){
        cin >> temp1 >> temp2;
        dic[temp1] = mp(true, temp2);
    }
    while(k--){
        cin >> temp1;
        if(dic[temp1].first){ cout << dic[temp1].second << endl; }
        else{
            ll ssize = temp1.size();
            bool changed = false;
            if(ssize >= 2){
                if(temp1[ssize-1] == 'y' and temp1[ssize-2] != 'a' and temp1[ssize-2] != 'e' and temp1[ssize-2] != 'i' and temp1[ssize-2] != 'o'  and temp1[ssize-2] != 'u'){
                    temp1[ssize-1] = 'i';
                    temp1 += "es"; changed = true;
                }
                else if(temp1[ssize-1] == 'o' or temp1[ssize-1] == 's' or temp1[ssize-1] == 'x'){
                    temp1 += "es"; changed = true;
                }
                else if(temp1[ssize-1] == 'h' and temp1[ssize-2] == 'c'){
                    temp1 += "es"; changed = true;
                }
                else if(temp1[ssize-1] == 'h' and temp1[ssize-2] == 's'){
                    temp1 += "es"; changed = true;
                }
            }
            if(!changed) temp1 += 's';
            cout << temp1 << endl;
        }
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}