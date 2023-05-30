#include <bits/stdc++.h>
using namespace std;
 
#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
// #define pop              pop_back
 
#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
 
#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(distance(x.begin(),unique(x.begin(),x.begin()+y)))
 
#define EPS              (1e-7)
#define MAX              (1e6+7)
#define MOD              (int)(1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

unordered_map < int, int > um;
void solve(){
    int n;
    cin >> n;
    um.clear();
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        um[temp%3]++;
    }
    int limit = n/3;

    int zero = um[0];
    int one = um[1];
    int two = um[2];

    // cout << zero <<  ' ' << one << ' ' << two << endl;

    int cost = 0;

    if(zero == one and one == two){
        cout << cost << endl;
        return;
    }

    // bug;
    
    if(zero > limit and one < limit){
        int besi = zero - limit;
        int lagbe = limit - one;

        zero -= min(lagbe, besi);
        one += min(lagbe, besi);

        cost += min(lagbe, besi);
        // bug;
    }

    if(zero == one and one == two){
        cout << cost << endl;
        return;
    }

    if(one > limit and two < limit){
        int besi = one - limit;
        int lagbe = limit - two;

        one -= min(lagbe, besi);
        two += min(lagbe, besi);

        cost += min(lagbe, besi);
    }

    if(zero == one and one == two){
        cout << cost << endl;
        return;
    }

    if(two > limit and zero < limit){
        int besi = two - limit;
        int lagbe = limit - zero;

        two -= min(lagbe, besi);
        zero += min(lagbe, besi);

        cost += min(lagbe, besi);
        // bug;
    }

    // cout << zero <<  ' ' << one << ' ' << two << endl;

    if(zero == one and one == two){
        cout << cost << endl;
        return;
    }

    if(zero > limit and two < limit){
        int besi = zero - limit;
        int lagbe = limit - two;

        zero -= min(lagbe, besi);
        two += min(lagbe, besi);

        cost += min(lagbe, besi)*2;
    }

    if(zero == one and one == two){
        cout << cost << endl;
        return;
    }

    if(one > limit and zero < limit){
        int besi = one - limit;
        int lagbe = limit - zero;

        one -= min(lagbe, besi);
        zero += min(lagbe, besi);

        cost += min(lagbe, besi)*2;
    }

    if(zero == one and one == two){
        cout << cost << endl;
        return;
    }

    if(two > limit and one < limit){
        int besi = two - limit;
        int lagbe = limit - one;

        two -= min(lagbe, besi);
        one += min(lagbe, besi);

        cost += min(lagbe, besi)*2;
    }

    cout << cost << endl;
    
}

int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }
 
}