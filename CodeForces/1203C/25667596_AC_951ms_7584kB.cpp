#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define vi              vector< int >
#define vll             vector< ll >
#define vc              vector< char >
#define vs              vector< string >
#define pb              push_back
#define all(v)          v.begin(), v.end()
#define PI              acos(-1.0)  // 3.1415926535897932
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define EPS             1e-9
#define INF             (1<<30)
#define MOD             10007
#define SIZ             1005
 
long long unsigned int GCD(long long unsigned int x, long long unsigned int y)
{
    if (x == 0)
        return y;
    return GCD(y%x, x);
}
 
int main()
{
    long long unsigned int n;
    cin >> n;
    long long unsigned int a[n];
    for(long long unsigned int i=0; i<n; i++)
        cin >> a[i];
    ll gcd=a[0];
    for(long long unsigned int i=1; i<n; i++)
        gcd = GCD(a[i], gcd);
    set <long long unsigned int> gdiv;
    for(long long unsigned int i=1; i<=sqrt(gcd); i++)
    {
        if(gcd%i==0)
        {
            gdiv.insert(i);
            if(i*i!=gcd)
                gdiv.insert(gcd/i);
        }
    }
    cout << gdiv.size() << endl;
}