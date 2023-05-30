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
#define Freopen          freopen("joke.in", "r", stdin); freopen("joke.out", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.4fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)

#define EPS              (1e-7)
#define MAX              (100007)
#define MOD              (1000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define LOG(b, x)        (log(x)/log(b))

template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }

ll n;
bool found;
vector < ll > container;
vector < bool > flag(51);

bool checker(string &str, ll index, ll num){
    map < ll , ll > feq1;
    for(ll i = index+1; i < str.size(); i++) feq1[(ll)str[i]-48]++;
    map < ll , ll > feq2;
    for(ll i = 1; i <= n; i++){
        if(i == num) continue;
        if(!flag[i]){
            ll x = i;
            while(x){
                feq2[x%10]++;
                x /= 10;
            }
        }
    }
    if(feq1 == feq2) return true;
    else return false;
}

void BT(string &str, ll index){
    if(found) return;
    if(container.size() == n){
        for(ll i = 0; i < n; i++){
            if(i+1 == n) cout << container[i] << endl;
            else cout << container[i] << ' ';
        }
        found = true;
        return;
    }
    if(index == str.size()) return;
    ll num = str[index]-48;
    if(!flag[num] and checker(str, index, num)){
        flag[num] = true;
        container.pb(num);
        BT(str, index+1);
        flag[num] = false;
        container.pop();
    }
    if(index+1 == str.size()) return;
    num = ((str[index]-48)*10) + (str[index+1]-48);
    if(flag[num] == false and checker(str, index+1, num)){
        flag[num] = true;
        container.pb(num);
        BT(str, index+2);
        flag[num] = false;
        container.pop();
    }
}

int main(){

    FastIO;
/*#ifndef ONLINE_JUDGE
    Clock; 
#endif*/
    Freopen;

    string str;
    while(cin >> str){
        if(str.size() <= 9) n = str.size();
        else n = ((str.size()-9)/2)+9;
        container.clear();
        BT(str, 0);
        found = false;
    }
/*
#ifndef ONLINE_JUDGE
    Runtime;
#endif*/

}
