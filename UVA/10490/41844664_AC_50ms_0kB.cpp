#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1.5e7 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

vector < ll > primes;
vector < bool > ifprime(maxx);

void Sieve() {
    for (ll i = 3; i * i <= maxx; i += 2) {
        if (!ifprime[i]) {
            for (ll j = i * i; j < maxx; j += i + i) {
                ifprime[j] = true;
            }
        }
    }
    primes.pb(2);
    for (ll i = 3; i < maxx; i += 2) if (!ifprime[i]) primes.pb(i);
}

ll binpow(ll n, ll p) {
    if (p == 0) return 1;
    ll res = binpow(n, p / 2);
    if (p % 2) return res * res * n;
    else return res * res;
}

ll sumofdivisors(ll n) {
    ll sum = 1;
    for (ll i = 0; primes[i]*primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            ll cnt = 1;
            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }
            sum *= (pow(primes[i], cnt) - 1) / (primes[i] - 1);
        }
    }
    if (n > 1) sum *= (pow(n, 2) - 1) / (n - 1);
    return sum;
}

bool pcheck(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(n & 1)) return false;
    if (!ifprime[n]) return true;
    else return false;
}

ll pre[40];
void solve() {
    ll n;
    while (cin >> n and n) {
        ll pnum = binpow(2, n - 1);
        pnum *= (binpow(2, n) - 1);

        ll sum = pre[n];

        if (sum == pnum) cout << "Perfect: " << pnum << "!" << endl;
        else {
            if (pcheck(n)) cout << "Given number is prime. But, NO perfect number is available." << endl;
            else cout << "Given number is NOT prime! NO perfect number is available." << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    Sieve();
    for (ll n = 2; n <= 31; n++) {
        ll pnum = binpow(2, n - 1);
        pnum *= (binpow(2, n) - 1);
        ll sum = sumofdivisors(pnum) - pnum;
        pre[n] = sum;
    }
    solve();

    return 0;
}