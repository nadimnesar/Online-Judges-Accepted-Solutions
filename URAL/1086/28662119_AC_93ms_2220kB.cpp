#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
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
    for (int p = 2; p < MAX; p++)
    {
        if (ifprime[p]== true)
        {
            primes.push_back(p);
        }
    }
}
int main()
{
    int t, n;
    vector<int> primes;
    Sieve(primes);
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << primes[n-1] << endl;
    }
}
