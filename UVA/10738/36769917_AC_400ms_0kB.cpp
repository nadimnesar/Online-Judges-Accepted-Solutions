#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define pqueue              priority_queue<ll,vector<ll>,greater<ll>>
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

vector < ll > primes;
vector < bool > ifprime(maxx);
void Sieve(){
    for(ll i = 3; i*i <= maxx; i+=2){
        if(!ifprime[i]){
            for(ll j = i*i; j < maxx; j += i+i){
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for(ll i = 3; i < maxx; i+=2) if(!ifprime[i]) primes.pb(i);
}

ll mu[1000007];
ll M[1000007];

void solve() {
    mu[1] = 1;
    M[1] = 1;
    for(ll i = 2; i <= 1e6; i++){
        ll n = i;
        ll total = 0;
        bool flag = true;
        for(ll j = 0; primes[j]*primes[j] <= n; j++){
            if(n%primes[j] == 0){
                ll cnt = 0;
                while(n%primes[j] == 0){
                    cnt++;
                    n /= primes[j];
                }
                if(cnt > 1) flag = false;
                
                total += cnt;
            }
        }
        if(n > 1) total++;
        if((i == 2) or (i&1 and !ifprime[i]) or (flag == true)){
            if(total&1){
                mu[i] = -1;
                M[i] = M[i-1]-1;
            }
            else{
                mu[i] = 1;
                M[i] = M[i-1]+1;
            }
        }
        else{
            mu[i] = 0;
            M[i] = M[i-1];
        }
    }

    ll m;
    while(cin >> m and m){
        ll temp = 8 - (to_string(m)).size();
        while(temp--) cout << ' ';
        cout << m;

        temp = 8 - (to_string(mu[m])).size();
        while(temp--) cout << ' ';
        cout << mu[m];

        temp = 8 - (to_string(M[m])).size();
        while(temp--) cout << ' ';
        cout << M[m] << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Sieve();

    /*int t, cn = 0;
    cin >> t;
    while(t--){
        // cout << "Case #" << ++cn << ": ";
        solve();
    }*/

    solve();

    return 0;
}