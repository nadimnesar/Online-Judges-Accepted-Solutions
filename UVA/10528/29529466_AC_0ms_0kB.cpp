/*Main Kahini akhane

C -> C, D, E, F, G, A, B, C

C# -> C#, D#, F, F#, G#, A#, C, C#

D -> D, E, F#, G, A, B, C#, D

D# -> D#, F, G, G#, A#, C, D, D#

E -> E, F#, G#, A, B, C#, D#

F -> F, G, A, A#, C, D, E, F

F# -> F#, G#, A#, B, C#, D#, F, F#

G -> G, A, B, C, D, E, F#, G

G# -> G#, A#, C, C#, D#, F, G, G#

A -> A, B, C#, D, E, F#, G#, A

A# -> A#, C, D, D#, F, G, A, A# 

B -> B, C#, D#, E, F#, G#, A#, B

*/



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

vector < vector < string > > majorscales;

void solve(){
    vector < string > temp;
    temp.pb("C"); temp.pb("D"); temp.pb("E"); temp.pb("F"); temp.pb("G"); temp.pb("A"); temp.pb("B");
    majorscales.pb(temp); temp.clear();
    temp.pb("C#"); temp.pb("D#"); temp.pb("F"); temp.pb("F#"); temp.pb("G#"); temp.pb("A#"); temp.pb("C");
    majorscales.pb(temp); temp.clear();
    temp.pb("D"); temp.pb("E"); temp.pb("F#"); temp.pb("G"); temp.pb("A"); temp.pb("B"); temp.pb("C#");
    majorscales.pb(temp); temp.clear();
    temp.pb("D#"); temp.pb("F"); temp.pb("G"); temp.pb("G#"); temp.pb("A#"); temp.pb("C"); temp.pb("D");
    majorscales.pb(temp); temp.clear();
    temp.pb("E"); temp.pb("F#"); temp.pb("G#"); temp.pb("A"); temp.pb("B"); temp.pb("C#"); temp.pb("D#");
    majorscales.pb(temp); temp.clear();
    temp.pb("F"); temp.pb("G"); temp.pb("A"); temp.pb("A#"); temp.pb("C"); temp.pb("D"); temp.pb("E");
    majorscales.pb(temp); temp.clear();
    temp.pb("F#"); temp.pb("G#"); temp.pb("A#"); temp.pb("B"); temp.pb("C#"); temp.pb("D#"); temp.pb("F");
    majorscales.pb(temp); temp.clear();
    temp.pb("G"); temp.pb("A"); temp.pb("B"); temp.pb("C"); temp.pb("D"); temp.pb("E"); temp.pb("F#");
    majorscales.pb(temp); temp.clear();
    temp.pb("G#"); temp.pb("A#"); temp.pb("C"); temp.pb("C#"); temp.pb("D#"); temp.pb("F"); temp.pb("G");
    majorscales.pb(temp); temp.clear();
    temp.pb("A"); temp.pb("B"); temp.pb("C#"); temp.pb("D"); temp.pb("E"); temp.pb("F#"); temp.pb("G#");
    majorscales.pb(temp); temp.clear();
    temp.pb("A#"); temp.pb("C"); temp.pb("D"); temp.pb("D#"); temp.pb("F"); temp.pb("G"); temp.pb("A");
    majorscales.pb(temp); temp.clear();
    temp.pb("B"); temp.pb("C#"); temp.pb("D#"); temp.pb("E"); temp.pb("F#"); temp.pb("G#"); temp.pb("A#");
    majorscales.pb(temp); return;
}


int main(){

#ifndef ONLINE_JUDGE
    Clock;
    Freopen;
#endif

    solve();
    string str;
    while(getline(cin, str)){
        if(str == "END") break;
        vector < string > scales;
        string temp;
        for(ll i = 0; str[i]; i++){
            if(str[i] == ' '){
                scales.pb(temp);
                temp.clear();
            }
            else temp += str[i];
        }
        if(temp.size() > 0) scales.pb(temp);
        sort(full(scales));
        scales.resize(distance(scales.begin(), unique(full(scales))));
        ll l = 0;
        while(l  < scales.size()){
            if(scales[l] == "C") l++;
            else if(scales[l] == "C#") l++;
            else if(scales[l] == "D") l++;
            else if(scales[l] == "D#") l++;
            else if(scales[l] == "E") l++;
            else if(scales[l] == "F") l++;
            else if(scales[l] == "F#") l++;
            else if(scales[l] == "G") l++;
            else if(scales[l] == "G#") l++;
            else if(scales[l] == "A") l++;
            else if(scales[l] == "A#") l++;
            else if(scales[l] == "B") l++;
            else iremove(scales, l);
        }
        vector < string > keys;
        for(ll i = 0; i < majorscales.size(); i++){
            ll counter = 0;
            for(ll j = 0; j < scales.size(); j++){
                bool paisi = false;
                for(ll k = 0; k < majorscales[i].size(); k++){
                    if(scales[j] == majorscales[i][k]){
                        counter++;
                        paisi = true;
                        break;
                        cout << scales[j] << endl;
                    }
                }
                if(paisi) continue;
                else break;
            }
            if(counter == scales.size()) keys.pb(majorscales[i][0]);
        }
        for(ll i = 0; i < keys.size(); i++){
            if(i == (keys.size()-1)) cout << keys[i] << endl;
            else cout << keys[i] << ' ';
        }
        if(keys.size() == 0) cout << endl;
    }


#ifndef ONLINE_JUDGE
    Runtime;
#endif
 
}