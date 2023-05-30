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
#define MAX             15000
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int digit(ull dig)
{
    ll d=0;
    while(dig)
    {
        d++;
        dig/=10;
    }
    return d;
}

int sumofn(ull N)
{
    ll d=0, sum=0;
    while(N)
    {
        sum+=N%10;
        N/=10;
    }
    if(digit(sum)==1) return sum;
    else return sumofn(sum);
}

int main()
{
    FASTIO;
    while(1)
    {
        ull n;
        cin >> n;
        if(n==0) break;
        cout << sumofn(n) << endl;
    }
}
