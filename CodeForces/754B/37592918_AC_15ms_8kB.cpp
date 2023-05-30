#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

vector < string > v;

bool valid(ll r, ll c){
    if(r < 0 or r >= 4) return false;
    if(c < 0 or c >= 4) return false;
    if(v[r][c] == 'o') return false;
    return true;
}

void solve() {
    string str;
    for(ll i = 0; i < 4; i++){
        cin >> str;
        v.pb(str);
    }

    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < 4; j++){
            if(v[i][j] == 'x'){
                if(valid(i-1, j+1) and valid(i+1, j-1)){
                    ll cnt = 1;

                    if(v[i-1][j+1] == 'x') cnt++;
                    if(v[i+1][j-1] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

                if(valid(i-1, j-1) and valid(i+1, j+1)){
                    ll cnt = 1;

                    if(v[i-1][j-1] == 'x') cnt++;
                    if(v[i+1][j+1] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

                if(valid(i-1, j) and valid(i+1, j)){
                    ll cnt = 1;

                    if(v[i-1][j] == 'x') cnt++;
                    if(v[i+1][j] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

                if(valid(i, j-1) and valid(i, j+1)){
                    ll cnt = 1;

                    if(v[i][j-1] == 'x') cnt++;
                    if(v[i][j+1] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }
            }

            if(v[i][j] == '.'){

                if(valid(i-1, j+1) and valid(i+1, j-1)){
                    ll cnt = 0;

                    if(v[i-1][j+1] == 'x') cnt++;
                    if(v[i+1][j-1] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

                if(valid(i-1, j-1) and valid(i+1, j+1)){
                    ll cnt = 0;

                    if(v[i-1][j-1] == 'x') cnt++;
                    if(v[i+1][j+1] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

                if(valid(i-1, j) and valid(i+1, j)){
                    ll cnt = 0;

                    if(v[i-1][j] == 'x') cnt++;
                    if(v[i+1][j] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

                if(valid(i, j-1) and valid(i, j+1)){
                    ll cnt = 0;

                    if(v[i][j-1] == 'x') cnt++;
                    if(v[i][j+1] == 'x') cnt++;

                    if(cnt >= 2){
                        cout << "YES" << endl;
                        return;
                    }
                }

            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    
    solve();

    return 0;
}