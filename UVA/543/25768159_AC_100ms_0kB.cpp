#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             long long unsigned int
#define vll             vector< ll >
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define point(x)        fixed << setprecision(x)
#define PI              acos(-1.0) //3.1415926535897932
#define EPS             1e-9
#define MAX             10001
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void Sieve(vector<int> &primes)
{
    bool ifprime[MAX];
    memset(ifprime, true, sizeof(ifprime));
    for (int p=2; p*p < MAX; p++)
    {
        if (ifprime[p] == true)
        {
            for (int i = p*p ; i < MAX ; i+=p)
                ifprime[i] = false;
        }
    }
    for (int p = 3; p < MAX; p++)
        if (ifprime[p]) primes.push_back(p);
}

bool isPrime(ll n)
{
    for (ll i=3; i*i<=n; i+=2)
        if (n%i==0) return false;
    return true;
}

int main()
{
    FASTIO;
    vector <int> primes;
    Sieve(primes);
    while(1)
    {
        ll temp;
        cin >> temp;
        if(temp==0) break;
        else
        {
            for(ll i=0; i < MAX; i++)
            {
                ll check=temp-primes[i];
                if(check%2==0) continue;
                else if(isPrime(check))
                {
                    cout << temp << " = " << primes[i] << " + " << check << endl;
                    break;
                }
                else continue;
            }
        }
    }
}