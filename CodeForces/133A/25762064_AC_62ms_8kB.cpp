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

int main()
{
    FASTIO;
    string str;
    getline(cin, str);
    ll y=0, len=str.size();
    for(ll i=0; i<len; i++)
    {
        if(str[i]=='Q' || str[i]=='H' || str[i]=='9')
        {
            y++;
            break;
        }
    }
    if(y) YES;
    else NO;
}