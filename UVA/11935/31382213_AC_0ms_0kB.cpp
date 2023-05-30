#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define ff                  first
#define ss                  second
#define pb                  push_back
#define pob                 pop_back
#define in                  insert
#define pf                  printf
#define sf                  scanf

#define full(x)             x.begin(),x.end()
#define rfull(x)            x.rbegin(),x.rend()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define rremove(x, y)       x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)       x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
#define fastIO              ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#define EPS                 (1e-7)
#define MAX                 (4e4+7)
#define MOD                 (1e9+7)
#define PI                  (acos(-1.0))
#define LOG(b, x)           (log(x)/log(b))

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename T> void __f(const char* X, T &&Y){cerr <<'#'<<X<<": "<<Y<<endl;}
template <typename T, typename... Z> void __f(const char* N, T&& Y, Z &&...M){cerr<<'#';
const char* C=strchr(N+1,','); cerr.write(N,C-N)<<": "<<Y<<" | ";__f(C+1,M...);}

typedef struct node{
    ll p = 0;
    ll f = 0;
    string c = "";
} node;

vector < node > rode;

node cmd_maker(string str){
    node x;
    int i = 0;
    for(; str[i] != ' '; i++) x.p = (x.p*10) + (str[i]-'0');
    ++i; bool flag = false;
    for(; str[i]; i++){
        if(str[i] >= '0' and str[i] <= '9'){
            flag = true;
            break;
        }
        else x.c += str[i];
    }
    if(flag){
        iremove(x.c, x.c.size()-1);
        for(; str[i]; i++) x.f = (x.f*10) + (str[i]-'0');
    }
    return x;
}

bool checker(double volume){
    ll n = rode.size(), leak = 0, fuel = 0, pos = 0;
    double tank = 0.00;
    double maxi = 0.00;

    for(int i = 0; i < n; i++){
        if(rode[i].c == "Fuel consumption"){
            ll dis = (rode[i].p - pos);
            tank += (dis*fuel)/100.00;
            tank += dis*leak;

            maxi = max(tank, maxi);

            pos = rode[i].p;
            fuel = rode[i].f;
        }
        else if(rode[i].c == "Leak"){
            ll dis = (rode[i].p - pos);
            tank += (dis*fuel)/100.00;
            tank += dis*leak;

            maxi = max(tank, maxi);

            leak++;
            pos = rode[i].p;
        }
        else if(rode[i].c == "Gas station"){
            ll dis = (rode[i].p - pos);
            tank += (dis*fuel)/100.00;
            tank += dis*leak;

            maxi = max(tank, maxi);

            pos = rode[i].p;
            tank = 0;
        }
        else if(rode[i].c == "Mechanic"){
            ll dis = (rode[i].p - pos);
            tank += (dis*fuel)/100.00;
            tank += dis*leak;

            maxi = max(tank, maxi);
            pos = rode[i].p;
            leak = 0;
        }
        else{
            ll dis = (rode[i].p - pos);
            tank += (dis*fuel)/100.00;
            tank += dis*leak;

            maxi = max(tank, maxi);
            pos = rode[i].p;
        }

        // debug(pos,fuel);
    }

    if(maxi <= volume) return true;
    else return false;
}

void solve(){
    node x;
    string temp;
    while(getline(cin, temp)){
        x = cmd_maker(temp);
        if(!(x.f) and !(x.p)) break;

        rode.clear();
        rode.pb(x);

        while(getline(cin, temp)){
            x = cmd_maker(temp);
            rode.pb(x);

            if(x.c == "Goal") break;
        }

        double res;
        double low = 0.000;
        double high = LLONG_MAX;

         while(abs(low - high) > EPS){
            double mid = (high+low)/2.0;
            if(checker(mid)){
                res = mid;
                high = mid;
            }
            else low = mid;
        }

        cout << dot(3) << res << endl;
    }
}

int main(){

    fastIO;
    solve();
    return 0;

}