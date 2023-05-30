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

vector < string > word_dic;

void BT(string str, vector < string > store, ll start, ll digitINDEX, ll wordINDEX){
    if(store.size() == str.size()){
        for(ll i = 0; i < store.size(); i++){
            cout << store[i];
        }
        cout << endl;
        return;
    }
    for(ll i = start; i < str.size(); i++){
        if(str[i] == '0'){
            for(ll j = digitINDEX; j <= 9; j++){
                store.pb(to_string(j));
                BT(str, store, i+1, digitINDEX, wordINDEX);
                store.pop_back();
            }
        }
        else{
            for(ll j = wordINDEX; j < word_dic.size(); j++){
                store.pb(word_dic[j]);
                BT(str, store, i+1, digitINDEX, wordINDEX);
                store.pop_back();
            }
        }
    }
}

int main(){
 
    FastIO;
#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    ll d;
    while(cin >> d){
        cout << "--" << endl;
        for(ll i = 0; i < d; i++){
            string temp; cin >> temp;
            word_dic.pb(temp);
        }

        ll n; cin >> n;
        for(ll i = 0; i < n; i++){
            string temp; cin >> temp;
            vector < string > store;
            BT(temp, store, 0, 0, 0);
        }
        word_dic.clear();
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}