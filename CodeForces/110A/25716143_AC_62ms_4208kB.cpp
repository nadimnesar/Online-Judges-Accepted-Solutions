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
    string num;
    cin >> num;
    ll len=num.size(), c=0;
    bool luck = true;
    for(ll i=0; i<len; i++)
    {
        if(num[i]=='4' || num[i]=='7')
        {
            c++;
            continue;
        }
    }
    if(c==0) luck = false;
    else if(c==4 || c==7) luck = true;
    else luck = false;
    if(luck) YES;
    else NO;
}