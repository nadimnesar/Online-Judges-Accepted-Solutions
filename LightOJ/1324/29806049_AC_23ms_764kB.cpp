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

string decToBinary(ll n, ll s){
    string binary;
    while(n){
        binary += (n%2)+48; 
        n /= 2;
    }
    while(binary.size() < s) binary += '0';
    reverse(full(binary));
    return binary; 
}

bool first_breket(string str, ll &s){
    bool paisi = false;
    for(ll i = 0; str[i]; i++){
        if(str[i] == '('){
            s = i;
            paisi = true;
        }
    }
    return paisi;
}

bool not_ase(string str, ll s, ll &last){
    bool ase = false;
    for(ll i = s+1; str[i] != ')'; i++){
        if(str[i] == '!'){
            ase = true;
            last = i;
        }
    }
    return ase;
}

bool not_ase_full(string str, ll &last){
    bool ase = false;
    for(ll i = 0; str[i]; i++){
        if(str[i] == '!'){
            ase = true;
            last = i;
        }
    }
    return ase;
}

bool magic_mosla(string str, string binary){
    for(ll i = 0; str[i]; i++){
        if(str[i] >= 'a' and str[i] <= 'j'){
            str[i] = binary[str[i]-'a'];
        }
    }
    ll s;
    while(first_breket(str, s)){
        ll last;
        while(not_ase(str, s, last)){
            str[last] = ' ';
            if(str[last+1] == '0') str[last+1] = '1';
            else if(str[last+1] == '1') str[last+1] = '0';
            remove(str, ' ');
        }
        for(ll i = s+1; str[i] != ')'; i++){
            if(str[i] == '&'){
                str[i] = ((str[i-1]-48)&(str[i+1]-48))+48;
                str[i-1] = ' ';
                str[i+1] = ' ';
                remove(str, ' ');
                i = s;
            }
        }
        for(ll i = s+1; str[i] != ')'; i++){
            if(str[i] == '|'){
                str[i] = ((str[i-1]-48)|(str[i+1]-48))+48;
                str[i-1] = ' ';
                str[i+1] = ' ';
                remove(str, ' ');
                i = s;
            }
        }
        str[s] = ' ';
        for(ll i = s+1; str[i]; i++){ if(str[i] == ')'){ str[i] = ' '; break; } }
        remove(str, ' ');
    }
    ll last;
    while(not_ase_full(str, last)){
        str[last] = ' ';
        if(str[last+1] == '0') str[last+1] = '1';
        else if(str[last+1] == '1') str[last+1] = '0';
        remove(str, ' ');
    }
    for(ll i = 0; str[i]; i++){
        if(str[i] == '&'){
            str[i] = ((str[i-1]-48)&(str[i+1]-48))+48;
            str[i-1] = ' ';
            str[i+1] = ' ';
            remove(str, ' ');
            i = -1;
        }
    }
    for(ll i = 0; str[i]; i++){
        if(str[i] == '|'){
            str[i] = ((str[i-1]-48)|(str[i+1]-48))+48;
            str[i-1] = ' ';
            str[i+1] = ' ';
            remove(str, ' ');
            i = -1;
        }
    }
    if(str[0] == '1') return true;
    else return false;
}

int main(){

    FastIO;
#ifndef ONLINE_JUDGE
    Clock; Freopen;
#endif

    ll cn = 0; ll t; cin >> t;
    while(t--){
        string ex1, ex2; cin >> ex1 >> ex2;
        map < char , ll > feq;
        for(ll i = 0; ex1[i]; i++) if(ex1[i] >= 'a' and ex1[i] <= 'j') feq[ex1[i]]++;
        for(ll i = 0; ex2[i]; i++) if(ex2[i] >= 'a' and ex2[i] <= 'j') feq[ex2[i]]++;
        ll ascii = 97;
        for(auto it = feq.begin(); it != feq.end(); it++){
            for(ll i = 0; ex1[i]; i++){
                if(it -> first == ex1[i]){
                    ex1[i] = (char)ascii;
                }
            }
            for(ll i = 0; ex2[i]; i++){
                if(it -> first == ex2[i]){
                    ex2[i] = (char)ascii;
                }
            }
            ascii++;
        }
        //cout << ex1 << endl;
        //cout << ex2 << endl;
        ll variables = feq.size();
        vector < bool > truth_table_ex1, truth_table_ex2;
        for(ll mask = 0; mask < (1 << variables); mask++){
            string temp = decToBinary(mask, variables);
            truth_table_ex1.pb(magic_mosla(ex1, temp));
            truth_table_ex2.pb(magic_mosla(ex2, temp));
        }

        /*for(ll i = 0; i < truth_table_ex1.size(); i++){
            cout << truth_table_ex1[i] << ' ';
        }
        cout << endl;

        for(ll i = 0; i < truth_table_ex2.size(); i++){
            cout << truth_table_ex2[i] << ' ';
        }
        cout << endl;*/

        cout << "Case " << ++cn << ": ";
        if(truth_table_ex1 == truth_table_ex2) cout << "Equivalent" << endl;
        else cout << "Not Equivalent" << endl;
    }

#ifndef ONLINE_JUDGE
    Runtime;
#endif

}